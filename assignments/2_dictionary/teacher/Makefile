AFLAGS=-felf64
ASM=nasm

all: main

main: main.o dict.o lib.o
	ld -o main main.o dict.o lib.o

main.o: main.asm colon.inc words.inc
	$(ASM) $(AFLAGS) main.asm

lib.o: lib.asm 
	$(ASM) $(AFLAGS) lib.asm

dict.o: dict.asm 
	$(ASM) $(AFLAGS) dict.asm


clean:
	rm -f main.o lib.o dict.o main
