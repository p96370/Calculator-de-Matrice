CC=gcc
CFLAGS=-I
DEPS=*.c *.h

exec: proiect.o
	gcc -o exec proiect.o -Wall 

proiect.o: proiect.c
	gcc -Wall -c proiect.c

.PHONY: clean

run: exec
	./exec

clean:
	rm -f *.o exec