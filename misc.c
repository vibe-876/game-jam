#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define option_maker(name) \
  char name[2]; \
  name[1] = 0x0;


void game_message(char *message, signed int line) {
  int row, col;
  getmaxyx(stdscr, row, col);

  mvprintw((row / 2) + line, (col - strlen(message)) / 2, message);
}

void fullscreen_message(char *message, signed int line) {
  clear();
  game_message(message, line);
  getch();
}

char game_options(char **options, signed int offset) {
  int row, col;
  
  getmaxyx(stdscr, row, col);
  row = (row / 2) + offset;
  col = (col - strlen(*options)) / 2;
  
  for(int i = 0; *(options + i) != 0x0; i++) {
    mvprintw(row + i, col, *(options + i));
  }

  return(getch());
}
  
int game_img(char *filename) {
  int offset = 10;
  char art_line[64];
  FILE *art;
  
  if((art = fopen(filename, "r")) == 0x0) {
    fullscreen_message("cannot open image file!", 0);
    return(-1);
  }

  while(fgets(art_line, 63, art) != 0x0) {
    game_message(art_line, offset);
    offset++;
  }

  return(0);
}
