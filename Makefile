<<<<<<< HEAD
signals: signal.c
	gcc signal.c -o signalab 

CC = gcc

CFLAGS = -Wall -Wextra -srd=c99

TARGETS= signal1 signal2 timer

all: $(TARGETS)

singal1: singal1.c
	$(CC) $(CFLAGS) -o signal1 signal1.c

signal2: signal2.c 
	$(CC) $(CFLAGS) -o signal2 signal1.2.c

timer: timer.c 
	$(CC) $(CFLAGS) -o timer timer.c

clean:
	rm -f $(TARGETS)

.PHONY all clean
=======
prog1: main.c
	gcc main.c -o prog1

prog2: main2.c
	gcc main2.c -o prog2

my3proc: main3.c
	gcc main3.c -o my3proc
>>>>>>> 85edc29929bb73ea9a9f562d260603f6528c9612
