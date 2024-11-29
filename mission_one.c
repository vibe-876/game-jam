#include "main.h"
#include <ncurses.h>
#include <string.h>


int launch_one() {
  clear();
  game_message("A University student slowly scrolls through his phone, gazing upon his stocks.", -10);
  game_message("His long green hair hangs elegantly, as he rests his cowboy boots on the table.", -9);

  game_message("But before long, it hits him -- with all of the money he's been making, the tax-man is sure to he hot on his tail...", -6);
  game_message("This is the story of his great escape.", -5);
  
  getch();
  return(0);
}
