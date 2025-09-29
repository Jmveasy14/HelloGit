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