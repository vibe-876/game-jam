CC=gcc
CFLAGS=-g -O0 -lncurses -Wall -Wextra -Wshadow -Wunreachable-code
COBJS=misc.o mission_one.o character.o
COUT=tax_evasion_over_telnet


default: $(COBJS)
	$(CC) $(CFLAGS) -o $(COUT) main.c $^

mission_one.o: mission_one.c
	$(CC) $(CFLAGS) -c $^

misc.o: misc.c
	$(CC) $(CFLAGS) -c $^

character.o: character.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm $(COUT) $(COBJS)
