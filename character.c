#include <ncurses.h>
#include <string.h>
#include "main.h"


void do_tax(character *person) {
  if(person == 0x0) return;
  person->liquid = person->liquid - (person->liquid * person->tax / 100);
}


void sell_gold(character *person) {
  if(person == 0x0) return;
  char gold[128];
  sprintf(gold, "%ld", person->gold);
  
  clear();
  game_message("How much gold would you like to sell? You have", -4);
  game_message(gold, -3);
  game_message("grams of gold", -2);
}
