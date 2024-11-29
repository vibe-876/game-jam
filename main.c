#include "main.h"
#include <ncurses.h>
#include <string.h>


int main(int argc, char **argv) {
  title_screen();

  return(0);
}

void title_screen() {
  int row, col;
  char title[] = "Tax Evasion Over Telnet!";
  char pak[] = "(press any key)";
  
  initscr();
  getmaxyx(stdscr, row, col);

  attron(A_BOLD);
  mvprintw(row / 2, (col - strlen(title)) / 2,
	   "%s", title);
  attroff(A_BOLD);
  
  mvprintw((row / 2) + 1, (col - strlen(title)) / 2,
	   "%s", pak);

  refresh();
  getch();
  endwin();
}
