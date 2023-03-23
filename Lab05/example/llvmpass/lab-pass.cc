/*
  Ref:
  * https://llvm.org/doxygen/
  * https://llvm.org/docs/GettingStarted.html
  * https://llvm.org/docs/WritingAnLLVMPass.html
  * https://llvm.org/docs/ProgrammersManual.html
  * https://stackoverflow.com/questions/28168815/adding-a-function-call-in-my-ir-code-in-llvm
  * https://stackoverflow.com/questions/30234027/how-to-call-printf-in-llvm-through-the-module-builder-system
  * https://gite.lirmm.fr/grevy/llvm-tutorial/-/blob/master/src/exercise3bis/ReplaceFunction.cpp
 */
#include "lab-pass.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#include <random>

using namespace llvm;

char LabPass::ID = 0;

bool LabPass::doInitialization(Module &M) {
  return true;
}

static void dumpIR(Function &F)
{
  for (auto &BB : F) {
    errs() << "BB: " << "\n";
    errs() << BB << "\n";
  }
}

static Constant* getI8StrVal(Module &M, char const *str, Twine const &name) {
  LLVMContext &ctx = M.getContext();

  Constant *strConstant = ConstantDataArray::getString(ctx, str);

  GlobalVariable *gvStr = new GlobalVariable(M, strConstant->getType(), true,
    GlobalValue::InternalLinkage, strConstant, name);

  Constant *zero = Constant::getNullValue(IntegerType::getInt32Ty(ctx));
  Constant *indices[] = { zero, zero };
  Constant *strVal = ConstantExpr::getGetElementPtr(Type::getInt8PtrTy(ctx),
    gvStr, indices, true);

  return strVal;
}

static FunctionCallee printfPrototype(Module &M) {
  LLVMContext &ctx = M.getContext();

  FunctionType *printfType = FunctionType::get(
    Type::getInt32Ty(ctx),
    { Type::getInt8PtrTy(ctx) },
    true);

  FunctionCallee printfCallee = M.getOrInsertFunction("printf", printfType);

  return printfCallee;
}

static FunctionCallee exitPrototype(Module &M) {
  LLVMContext &ctx = M.getContext();

  FunctionType *exitType = FunctionType::get(
    Type::getInt32Ty(ctx),
    { Type::getInt32Ty(ctx) },
    false);

  FunctionCallee exitCallee = M.getOrInsertFunction("exit", exitType);

  return exitCallee;
}

bool LabPass::runOnModule(Module &M) {
  errs() << "runOnModule\n";

  LLVMContext &ctx = M.getContext();
  std::random_device randDev;
  std::default_random_engine randEngine(randDev());
  std::uniform_int_distribution<unsigned int> uniformDist(0, 0xffffffff);

  FunctionCallee exitCallee = exitPrototype(M);
  FunctionCallee printfCallee = printfPrototype(M);

  Constant *stackBofMsg = getI8StrVal(M, "!!!STACK BOF!!!\n", "stackBofMsg");

  for (auto &F : M) {
    if (F.empty()) {
      continue;
    }

    errs() << F.getName() << "\n";

    Constant *one = Constant::getIntegerValue(Type::getInt32Ty(ctx), APInt(32, 1));

    unsigned int canary = uniformDist(randEngine);
    Constant *cCanary = Constant::getIntegerValue(Type::getInt32Ty(ctx), APInt(32, canary));

    BasicBlock &Bstart = F.front();
    BasicBlock &Bend = F.back();

    // Split "ret" from original basic block
    Instruction &ret = *(++Bend.rend());
    BasicBlock *Bret = Bend.splitBasicBlock(&ret, "ret");

    // Create epilogue BB before ret BB
    BasicBlock *Bepi = BasicBlock::Create(ctx, "epi", &F, Bret);

    // Create BB handling stack-based buffer overflow after epilogue BB (before ret BB)
    BasicBlock *Bbof = BasicBlock::Create(ctx, "bof", &F, Bret);

    // Patch the instruction at end of of Bend BB, "br ret", to "br epi"
    Instruction &br = *(++Bend.rend());
    IRBuilder<> BuilderBr(&br);

    BuilderBr.CreateBr(Bepi);

    br.eraseFromParent();

    // Insert code at prologue
    Instruction &Istart = Bstart.front();
    IRBuilder<> BuilderStart(&Istart);

    AllocaInst *aCanary = BuilderStart.CreateAlloca(Type::getInt32Ty(ctx), 0, "canary");
    BuilderStart.CreateStore(cCanary, aCanary);

    // New basic block for handling stack-based buffer overflow
    IRBuilder<> BuilderBof(Bbof);

    BuilderBof.CreateCall(printfCallee, { stackBofMsg });
    BuilderBof.CreateCall(exitCallee, { one });
    BuilderBof.CreateBr(Bret);

    // Insert code at epilogue
    IRBuilder<> BuilderEnd(Bepi);

    Value *i0 = BuilderEnd.CreateLoad(Type::getInt32Ty(ctx), aCanary);
    Value *eq = BuilderEnd.CreateICmpEQ(i0, cCanary);
    BuilderEnd.CreateCondBr(eq, Bret, Bbof);

    // Dump IR
    dumpIR(F);
  }

  return true;
}

static RegisterPass<LabPass> X("labpass", "Lab Pass", false, false);