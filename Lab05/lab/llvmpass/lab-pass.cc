/*
  Ref:
  * https://llvm.org/doxygen/
  * https://llvm.org/docs/GettingStarted.html
  * https://llvm.org/docs/WritingAnLLVMPass.html
  * https://llvm.org/docs/ProgrammersManual.html
 */
#include "lab-pass.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"

using namespace llvm;

char LabPass::ID = 0;

bool LabPass::doInitialization(Module &M) {
  return true;
}

bool LabPass::runOnModule(Module &M) {
  errs() << "runOnModule\n";

  for (auto &F : M) {
    errs() << F.getName() << "\n";

    // TODO
  }

  return true;
}

static RegisterPass<LabPass> X("labpass", "Lab Pass", false, false);