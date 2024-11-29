CC=gcc
CFLAGS=-g -O0 -lncurses
COUT=tax_evasion_over_telnet
CFILES=main.c main.h screens.c
COBJS=screens.o


default: $(COBJS)
	$(CC) $(CFLAGS) -o $(COUT) main.c $(COBJS)

screens.o: screens.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm $(COUT) $(COBJS)
