NASM=nasm -f macho64
LD=ld -macosx_version_min 10.7.0 -lSystem

all: 2_1_hello 2_4_hello_proper_exit 2_5_print_rax \
	2_10_print_call 2_11_endianness 2_13_false \
	2_14_strlen

2_1_hello: 2_1_hello.o
	$(LD) -o $@ $^
2_1_hello.o: 2_1_hello.asm
	$(NASM) $<

2_4_hello_proper_exit: 2_4_hello_proper_exit.o
	$(LD) -o $@ $^
2_4_hello_proper_exit.o: 2_4_hello_proper_exit.asm
	$(NASM) $<

2_5_print_rax: 2_5_print_rax.o
	$(LD) -o $@ $^
2_5_print_rax.o: 2_5_print_rax.asm
	$(NASM) $<

2_10_print_call: 2_10_print_call.o
	$(LD) -o $@ $^
2_10_print_call.o: 2_10_print_call.asm
	$(NASM) $<

2_11_endianness: 2_11_endianness.o
	$(LD) -o $@ $^
2_11_endianness.o: 2_11_endianness.asm
	$(NASM) $<

2_13_false: 2_13_false.o
	$(LD) -o $@ $^
2_13_false.o: 2_13_false.asm
	$(NASM) $<

2_14_strlen: 2_14_strlen.o
	$(LD) -o $@ $^
2_14_strlen.o: 2_14_strlen.asm
	$(NASM) $<

clean:
	$(RM) *.o 2_1_hello 2_4_hello_proper_exit 2_5_print_rax \
	2_10_print_call 2_11_endianess 2_13_false 2_14_strlen
