Lab 5
========

Create an LLVM Pass that can log the following message when a function is invoked:
* Indent N spaces before outputting, where N is the function depth, and define the depth of the main function as 0
* Function name
* Function address

You can only modify the files listed below:
* lab/llvmpass/lab-pass.cc
* lab/llvmpass/lab-pass.h

The output of the solution should resemble the following image:

![](https://i.imgur.com/cimRbvy.png)

(Note that due to ASLR and PIE, the addresses of the functions will be different in each execution, but the offset will remain the same.)
