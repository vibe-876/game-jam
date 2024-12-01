#include "character.h"
#include "missions.h"

void title_screen();

void game_message(char *message, signed int line);
void fullscreen_message(char *message, signed int line);
char game_options(char **options, signed int offset);
int game_img(char *filename, signed int offset);
