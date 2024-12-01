#include "main.h"
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>


int launch_one() {
  character *person = malloc(sizeof(character));
  person->gold = 4000;
  person->liquid = 0;
  person->tax = 28;
  
  one_intro();
  scene_one(person);
  return(0);
}


void one_intro() {
  clear();
  attron(A_BOLD);
  game_message("Episode One: Escape from Taxland", -6);
  attroff(A_BOLD);
  getch();
  
  game_message("A University student slowly gazes upon his 4kg of gold.", -10);
  game_message("His long green hair hangs elegantly, as he rests his cowboy boots on the table.", -9);

  game_message("But before long, it hits him -- with all of the money he's been making, the tax-man is sure to he hot on his tail...", -6);
  game_message("This is the story of his great escape.", -5);
  
  sbreak;
}

void scene_one(character *person) {
  char *options[] = {"[g] => goto shop", "[w] => invest in a gun, and prepare for HMRC", "[b] => buy more gold", "[n] => do nothing", 0x0};
  while(1) {
    clear();
  
    game_message("The really-observant-superb-seller University student looks again at his gold.", -6);
    game_message("If the tax man is on his tail, maybe he should try and sell the gold quickly, before he gets caught...", -5);
    game_message("He knows that there is a shop that buys gold just down the road.", -4);

    switch(game_options(options, 0)) {
    case 'b':
      no_money:
      clear();
      game_message("If only you had some money to do so.", -4);
      game_message("Unfortunately, all of the money that you couldn't spend on gold has gone to the university, because cost of living crisis or something.", -3);
      sbreak;

    case 'g':
      shop_scene_one(person);
      break;

    case 'n':
      clear();
      game_message("HMRC will be soon upon his tail...", -8);
      sbreak;

    case 'w':
      goto no_money;
    default:
    }
  }
}

void shop_scene_one(character *person) {
  char *options[] = {"[b] => buy some gold", "[s] => sell some gold", "[t] => sell gold and pay tax on it", "[c] => buy gold and pay tax on it", "[l] => leave and go back", 0x0};
  clear();
  game_message("You walk into a poorly lit shop. Dust and spiders are scattered against the red brick walls", -4);
  game_message("A woman of below average height, with long, tangled blonde hair tied poorly into a bun stairs at you, with an uncanny smile.", -3);
  game_message("\"Hello -- what can I do for you?\", she says after a short pause, never breaking eye contact with you.", -1);

  while(1) {
    switch(game_options(options, 2)) {
    case 'b':
      clear();
      if(person->liquid < GOLD_VALUE) {
	game_message("\"Well I would just love to sell you some,\" she says, in a slow, almost monotone voice,", -3);
      game_message("\"But you just can't afford any.\".", -2);
      } else {
	game_message("Buys gold.", -2);
	//buy_gold(person);
      } getch();
      clear();
      break;
      
    case 's':
      clear();
      sell_gold(person);
      clear();
      break;

    case 'l':
      clear();
      game_message("You walk home.", -2);
      getch();
      goto leave_shop;
    }
  } leave_shop:
}
