AFLAGS = -f elf64
all: main


main.o: main.asm
	nasm $(AFLAGS) -o main.o main.asm

libso.o: libso.asm
	nasm $(AFLAGS) -o libso.o libso.asm

libso.so: libso.o
	ld -shared -o libso.so libso.o

main: main.o libso.so
	ld -o main main.o -d libso.so --dynamic-linker=/lib64/ld-linux-x86-64.so.2

clean: 
	rm -f main.o libso.o libso.so main
