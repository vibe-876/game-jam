#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
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

/* No checking is done to see if the
 * char given is a valid one for the
 * given set of options, as that should
 * be handled by an external switch statment.
 */
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

/* I should probably add an additional argument
 * to change the row the "image" starts in.
 *
 * I might do that later, or I might sleep, who
 * knows.
 */
int game_img(char *filename) {
  int offset = 10;
  char art_line[64];
  FILE *art;
  
  if((art = fopen(filename, "r")) == 0x0) {
    fullscreen_message("cannot open image file!", 0);
    return(-1);
  }

  /* Don't know if fgets automatically adds 0x0
   * to the end, so just being safe. Feel free
   * to change to 64 if you know it's safe.
   */
  while(fgets(art_line, 63, art) != 0x0) {
    game_message(art_line, offset);
    offset++;
  }

  return(0);
}
