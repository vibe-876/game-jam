#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


void do_tax(character *person) {
  if(person == 0x0) return;
  person->liquid = person->liquid - (person->liquid * person->tax / 100);
}


void sell_gold(character *person) {
  if(person == 0x0) return;

  unsigned long to_sell;
  char gold[128];
  char selling_amount[128];
  char *end_ptr = 0x0;
  
  sprintf(gold, "%ld", person->gold);
  
  clear();
  game_message("How much gold would you like to sell? You have", -4);
  game_message(gold, -3);
  game_message("grams of gold", -2);
  game_message("(enter number, end with newline)", 0);

  getstr(selling_amount);
  to_sell = strtol(selling_amount, &end_ptr, 10);

  if(to_sell > person->gold)
    game_message("That's more gold than you have...", 2);
  else {
    person->gold -= to_sell;
    person->liquid += to_sell * GOLD_VALUE;
  }
}
