# Frequently asked questions

## How do I start writing assignments?

Go to the [assignments](assignments) directory. Pick up
the relevant subdirectory.

Each assignment directory has two subdirectories: `stud` and `teacher`. 
You should use the files provided in `stud`.
The `teacher` directory has the example solution.

## Where are the missing solutions?

Right now they are being double checked and quite soon I am going to put the rest of them in [assignments](assignments) directory.

## The file `x` is mentioned, where do I find it?

In this repository. If it is a listing, go to [listings](listings) directory. If this is a part of assignment, find the relevant assignment in [assignments](assignments) directory. 

For example, `lib.inc` is the file needed for the first assignment and it is located at [assignments/1_io_library/stud](assignments/1_io_library/stud). 


## x32 systems

We do not support x32 systems.

## Windows x64 systems

Windows 10 allows you to install WSL (Windows Subsystem for Linux). Use it to complete assignments.

Refer to the [official installation guide](https://msdn.microsoft.com/en-us/commandline/wsl/install_guide).

## MacOS support

We are _not_ officially supporting completing assembly assignments on Mac OS. The
C assignments, however, should work perfectly fine.

### How to perform syscalls 

The system calls numbers supplied in `rax` before `syscall` instruction is executed _are different_ on Mac OS. To find them:

1. Find your kernel version:

```
machine:~ user$ uname -v
Darwin Kernel Version 15.6.0: Thu Jun 23 18:25:34 PDT 2016; root:xnu-3248.60.10~1/RELEASE_X86_64
```
The version part is xnu-3248.60.10 

2. Go to the sources at: [https://opensource.apple.com/source/xnu/{KERNEL_VERSION}/bsd/kern/syscalls.master.auto.html](https://opensource.apple.com/source/xnu/{KERNEL_VERSION}/bsd/kern/syscalls.master.auto.html) E.g.
[https://opensource.apple.com/source/xnu/xnu-3248.60.10/bsd/kern/syscalls.master.auto.html](https://opensource.apple.com/source/xnu/xnu-3248.60.10/bsd/kern/syscalls.master.auto.html)

3. There you have syscall numbers in the first column. To make it work also add 0x2000000 to that number. E.g. for write call you need to pass not just 0x4, but 0x2000004

Links and example: [https://filippo.io/making-system-calls-from-assembly-in-mac-os-x/](https://filippo.io/making-system-calls-from-assembly-in-mac-os-x/)


### Problems with Virtual Machine

The problems are usually related to your host VM's network configuration.
E.g. see [this issue](https://github.com/Apress/low-level-programming/issues/54). 
