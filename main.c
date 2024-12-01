#include "main.h"
#include <ncurses.h>
#include <string.h>

/* should these two be merged into one
 * function?
 */
int main() {
  initscr();
  noecho();
  
  title_screen();

  endwin();
  return(0);
}


void title_screen() {
  char mode[2];
  char *options[] = {"[p] => play game", "[t] => play tutorial", "[c] => show credits", "[q] => quit", 0x0};
  mode[1] = 0x0;
    
  while(1) {
    clear();
    
    attron(A_BOLD);
    game_message("Tax Evasion Over Telnet!", -6);
    attroff(A_BOLD);
    game_message("exploring the wonders of tax evasion", -5);
  
    switch(mode[0] = game_options(options, -3)) {
    case 'c':
      clear();
  
      game_message("Game developers:", -5);
      game_message("Cam & Ross.", -4);

      game_message("And a special thanks to:", -2);
      game_message("Coffee, for giving us energy.", -1);
      
      sbreak;
      
    case 'p':
      launch_one();
      break;
      
    case 'q':
      goto exit;
      
    case 't':
      clear();
      game_message("If you want to leave at any time, just press C-c.", -4);
      game_message("(If you don't know what that means, read the emacs docs)", -3);

      game_message("If the screen stay on a single thing without any options, just whack a random key.", -1);

      game_message("Regrettably, the telnet part of Tax Evasion Over Telnet doesn't work, but who actually cares lol.", 2);

      sbreak;
      
    default:
      break;
    }
  } exit:
  
  refresh();
  return;
}
