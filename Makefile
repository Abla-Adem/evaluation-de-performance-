CC = gcc
CFLAGS = -Wall -lm -fopenmp -pthread -g -O3 -lm
all:./run
./run:main.c
	$(CC) $< -o $@ $(CFLAGS)
clean:
	rm -f *.o
	rm  run