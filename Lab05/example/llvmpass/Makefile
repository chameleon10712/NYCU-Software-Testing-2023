CXX := clang++-15
CXXFLAGS := -fno-rtti -fPIC `llvm-config-15 --cxxflags` `llvm-config-15 --ldflags` -shared

.PHONY: all
all: lab-pass.so

lab-pass.so: lab-pass.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -rf lab-pass.so
