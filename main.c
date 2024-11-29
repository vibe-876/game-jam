#include "main.h"
#include <ncurses.h>
#include <string.h>


int main(int argc, char **argv) {
  title_screen();

  return(0);
}

void title_screen() {
  int row, col;
  char message[] = "Tax Evasion Over Telnet!";
  
  initscr();
  getmaxyx(stdscr, row, col);

  mvprintw(row / 2, (col - strlen(message)) / 2,
	   "%s", message);

  refresh();
  getch();
  endwin();
}
