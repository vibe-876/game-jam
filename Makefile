CC=gcc
CFLAGS=-g -O0 -lncurses
COBJS=misc.o screens.o mission_one.o
COUT=tax_evasion_over_telnet


default: $(COBJS)
	$(CC) $(CFLAGS) -o $(COUT) main.c $^

screens.o: screens.c
	$(CC) $(CFLAGS) -c $^

mission_one.o: mission_one.c
	$(CC) $(CFLAGS) -c $^

misc.o: misc.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm $(COUT) $(COBJS)
