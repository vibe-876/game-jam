# The Much Awaited Documentation!
Documentation is for nerds, all of the cool people like me just read the assembler output and figure it out from there.

On a more serious note, this is meant to be read alongside the header file, which should be easy to find.

## Useful Functions
All of these are implemented in the misc.c source file, and are declared in the main.h header.


game\_message is used for writting messages to the screen. It takes 2 arguments: a string (ie char\*) to be displayed, and a displacement from the middle column given as a signed int. For example, to write "hello, world!" 2 rows above the centre of the screen, it would be
``` c
game_message("hello, world!", -2);
```
This syntax of (thing, offset) is in basically all of these functions (actually all of them until I write some more docs).


game\_options takes a list of strings (ie char\*\*) that **must** end with 0x0 or some equivalent -- and if you forget that the whole thing segfaults lol (I have good design skills I promise) -- and some offset (the same as game\_message).

It prints out each of these string on a newline, with the left of each aligned, and then takes some char as an input, which it then returns. The intended use for this is to create multiple choice menus, but I have this strange feeling that some other things can be done with it too...

The offset just affects what line the first element of the list is printed onto.

Because C, you should probably define the list first, like below:
``` c
char *option_msg[] = {"[a] => do thing a", "[b] => do thing b", "[c] => you get the idea", 0x0}
/* Starting the first line on the sixth
 * line from the middle.
 */
switch(game_options(option_msg, 6)) {
case 'a':
  // thing a
case 'b':
  // thing b
default:
  // bla bla bla
```
This function will not check if the returned value is one of the options, you should do all validation within your switch statement.


game\_img takes some filename, and just writes it to the screen, starting at offset (its second argument). Be careful, because it is a bit of an ascii purist, and doesn't seem to like non-ascii chars, but who knows, I might have just misconfigured my terminal.

## Money Functions
In main.h and character.c files.

People are implemented by the person_struct structure, which is typedef-ed to person for convince -- the implementation is shown below.
``` c
typedef struct character_struct {
  unsigned long gold; /* in grams */
  unsigned long liquid; /* ie, your liquid cash */
  unsigned char tax; /* Tax percent, no point in >1 byte */
} character;
```

The only function so far is doTax, which takes a pointer to some character as its only argument. It deducts taxes from the character. For example, taking the taxes from someone called coffee would be done as
``` c
person *coffee = malloc(sizeof(person));
// Give coffee their values here.
doTax(coffee);
```
Or, if you for some reason prefer your stuff on the stack:
``` c
person coffee;
// Give coffee their gross stack values.
doTax(&coffee);
```
