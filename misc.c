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
  signed int line = 10;
  char art_line[64];
  FILE *art;

  art = fopen(filename, "r");

  if(art == 0x0) {
    fprintf(stderr, "cannot open image file!");
    return(-1);
  }

  while(fgets(art_line, 63, art) != 0x0) {
    game_message(art_line, line);
    line++;
  }

  return(0);
} 
