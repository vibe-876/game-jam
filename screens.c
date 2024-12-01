/* Maybe move this entire file over to
 * main.c? It's just one function.
 */
#include "main.h"
#include <ncurses.h>
#include <string.h>


void title_screen() {
  char mode[2];
  char *options[] = {"[p] => play game", "[t] => play tutorial", "[c] => show credits", "[q] => quit", 0x0};
  mode[1] = 0x0;
    
  while(1) {
    clear();
    
    attron(A_BOLD);
    game_message("Tax Evasion Over Telnet!", -6);
    attroff(A_BOLD);
  
    switch(mode[0] = game_options(options, -4)) {
    case 'c':
      clear();
  
      game_message("Game developers:", -5);
      game_message("Cam & Ross.", -4);

      game_message("And a special thanks to:", -2);
      game_message("Coffee, for giving us energy.", -1);
      
      getch();
      break;
      
    case 'p':
      launch_one();
      break;
      
    case 'q':
      goto exit;
      
    case 't':
      fullscreen_message("tutorial not implemented yet :( .", -5);
      
      break;
      
    default:
      break;
    }
  } exit:
  
  refresh();
  return;
}
