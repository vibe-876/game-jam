#include <ncurses.h>
#include <string.h>


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
