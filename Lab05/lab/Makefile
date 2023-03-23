OPT := opt-15
LLC := llc-15
CC := clang-15

OPTFLAGS := -time-passes -enable-new-pm=0
CFLAGS := -O0 -emit-llvm -c

LLVMPASS_DIR := llvmpass/

.PHONY: all
all: newprog

newprog: main.bc $(LLVMPASS_DIR)/lab-pass.so
	$(OPT) $(OPTFLAGS) -load $(LLVMPASS_DIR)/lab-pass.so -labpass -o $@.bc $<
	$(CC) -o $@ $@.bc

main.bc: src/main.c
	$(CC) $(CFLAGS) -o $@ $<

$(LLVMPASS_DIR)/lab-pass.so:
	make -C $(LLVMPASS_DIR)

.PHONY: clean
clean:
	rm -rf newprog *.bc *.s *.ll
	make -C $(LLVMPASS_DIR) clean
	make -C src clean