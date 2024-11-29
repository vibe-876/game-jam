CC=gcc
CFLAGS=-g -O0 -lncurses
CMAIN=main.c
COUT=tax_evasion_over_telnet
CFILES=$(CMAIN) main.h


default: $(CFILES)
	$(CC) $(CFLAGS) -o $(COUT) $(CMAIN)


clean:
	rm $(COUT)
