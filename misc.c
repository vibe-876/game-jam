#include <ncurses.h>
#include <stdio.h>
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
  FILE *file = fopen(strcat("img/", filename), "r");
  if(file == 0x0) {
    perror("ERROR: File doesn't exist!");
    return(-1);
  }
  
  return(0);
} 
