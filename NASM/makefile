
all: hello.out 

hello.out: hello.asm
	nasm -f elf64 -o hello.o hello.asm
	ld	hello.o -o hello

recompile:
	rm -f *.out
	rm -f *.outc
	make all

clean:  # for moving to another platform, keeping results
	rm -f a.out
	rm -f *~
	rm -f core*
	rm -f *.o

initial:
	rm -f *.out
	rm -f *.outc
	rm -f *.lst
	rm -f *.s
	make clean

web:
	chgrp cseeweb *
	chmod go+rx *
	chmod g+w *

