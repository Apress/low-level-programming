# Frequently asked questions


## MacOS support

We are _not_ officially supporting completing assembly assignments on Mac OS. The
other ones should work perfectly fine.

### How to perform syscalls 

The system calls numbers supplied in `rax` before `syscall` instruction is executed _are different_ on Mac OS. To find them:

1. Find your kernel version:

machine:~ user$ uname -v
Darwin Kernel Version 15.6.0: Thu Jun 23 18:25:34 PDT 2016; root:xnu-3248.60.10~1/RELEASE_X86_64

The version part is xnu-3248.60.10 

2. Go to the sources at: [https://opensource.apple.com/source/xnu/{KERNEL_VERSION}/bsd/kern/syscalls.master.auto.html](https://opensource.apple.com/source/xnu/{KERNEL_VERSION}/bsd/kern/syscalls.master.auto.html) E.g.
[https://opensource.apple.com/source/xnu/xnu-3248.60.10/bsd/kern/syscalls.master.auto.html](https://opensource.apple.com/source/xnu/xnu-3248.60.10/bsd/kern/syscalls.master.auto.html)

3. There you have syscall numbers in the first column. To make it work also add 0x2000000 to that number. E.g. for write call you need to pass not just 0x4, but 0x2000004

Links and example: [https://filippo.io/making-system-calls-from-assembly-in-mac-os-x/](https://filippo.io/making-system-calls-from-assembly-in-mac-os-x/)


