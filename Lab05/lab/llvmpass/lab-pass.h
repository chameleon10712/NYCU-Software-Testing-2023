#ifndef LAB_PASS_H
#define LAB_PASS_H

#include "llvm/Pass.h"

namespace llvm {

class LabPass : public ModulePass {
public:
  static char ID;
  LabPass() : ModulePass(ID) {}

  bool doInitialization(Module &M) override;
  bool runOnModule(Module &M) override;
};

} // namespace llvm

#endif // LAB_PASS_H