tp1: tp1.o
	gcc -o tp1 tp1.o

tp1.o: tp1.c
	gcc -c tp1.c -W

.PHONY: clean

clean: 
	rm -f tp1 *.o
