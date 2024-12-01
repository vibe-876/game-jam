#include <ncurses.h>
#include <string.h>
#include "character.h"


void doTax(character *person) {
  if(person == 0x0) return;
  person->liquid -= (person->liquid / person->tax);
}
