CC=gcc
CFLAGS=-g -O0
CMAIN=main.c
COUT=main
CFILES=$(CMAIN) main.h


default: $(CFILES)
	$(CC) $(CFLAGS) -o $(COUT) $(CMAIN)


clean:
	rm $(COUT)
