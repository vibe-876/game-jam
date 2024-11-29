#include "main.h"
#include <ncurses.h>
#include <string.h>


void title_screen() {
  int row, col;
  char mode;
  char title_msg[] = "Tax Evasion Over Telnet!";
  char play_msg[] = "[p] => play game";
  char tutorial_msg[] = "[t] => play tutorial";
  char credits_msg[] = "[c] => show credits";
  char quit_msg[] = "[q] => quit";
    
  while(1) {
    getmaxyx(stdscr, row, col);
    row = (row / 2) - 5;
    clear();
    
    attron(A_BOLD);
    mvprintw(row, (col - strlen(title_msg)) / 2, "%s", title_msg);
    attroff(A_BOLD);

    col = (col - strlen(play_msg)) / 2;
    mvprintw(row + 2, col, "%s", play_msg);
    mvprintw(row + 3, col, "%s", tutorial_msg);
    mvprintw(row + 4, col, "%s", credits_msg);
    mvprintw(row + 5, col, "%s", quit_msg);
  
    switch(mode = getch()) {
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
      fullscreen_message("launching tutorial...", -5);
      break;
      
    default:
      break;
    }
  } exit:
  
  refresh();
  return;
}
