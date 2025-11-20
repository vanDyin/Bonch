all:
	nasm -f elf32 main.asm -o main.o
	ld -m elf_i386 main.o -o lab4

clean:
	rm -f main.o

cleanAll:
	rm -f main.o lab4

