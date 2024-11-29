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
  
  initscr();
  getmaxyx(stdscr, row, col);

  while(1) {
    clear();
    
    attron(A_BOLD);
    mvprintw(row / 2, (col - strlen(title_msg)) / 2, "%s", title_msg);
    attroff(A_BOLD);

    mvprintw((row / 2) + 2, (col - strlen(play_msg)) / 2, "%s", play_msg);
    mvprintw((row / 2) + 3, (col - strlen(play_msg)) / 2, "%s", tutorial_msg);
    mvprintw((row / 2) + 4, (col - strlen(play_msg)) / 2, "%s", credits_msg);
    mvprintw((row / 2) + 5, (col - strlen(play_msg)) / 2, "%s", quit_msg);
  
    noecho();
    switch(mode = getch()) {
    case 'c':
      credits();
      break;
      
    case 'p':
      mvprintw(0, 0, "starting game...");
      getch();
      break;
      
    case 'q':
      goto exit;
      
    case 't':
      mvprintw(0, 0, "launching tutorial...");
      getch();
      
    default:
      break;
    }
  } exit:
  
  refresh();
  endwin();
  return;
}

void credits() {
  int row, col;
  char credits_msg[] = "Game developers:";
  
  clear();

  getmaxyx(stdscr, row, col);
  row /= 2;
  col = (col - strlen(credits_msg)) / 2;
  
  attron(A_BOLD);
  mvprintw(row, col, "%s", credits_msg);
  attroff(A_BOLD);
  
  mvprintw(row + 1, col, "Cam & Ross.");
  getch();
}
