#include "main.h"
#include <ncurses.h>
#include <string.h>


int main(int argc, char **argv) {
  initscr();
  noecho();
  
  title_screen();

  endwin();
  return(0);
}
