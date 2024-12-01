#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


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
