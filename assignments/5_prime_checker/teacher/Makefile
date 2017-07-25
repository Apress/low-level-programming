all: main

main: main.o
	gcc -o main main.o

main.o: main.c
	gcc -c -o main.o main.c

clean:
	rm -f main.o main
