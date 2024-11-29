#include "main.h"
#include <ncurses.h>
#include <string.h>


int main() {
  initscr();
  noecho();
  
  title_screen();

  endwin();
  return(0);
}
