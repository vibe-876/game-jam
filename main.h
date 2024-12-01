/* Okay, you might want to be a bit careful
 * with this, because there is a chance for
 * confusion between char and character, but
 * I can't think of a better name due to the
 * magic of sleep deprivation, so feel free to
 * change it.
 */
typedef struct character_struct {
  unsigned long gold; /* in kg */
  unsigned long tax;
} character;


void title_screen();

void game_message(char *message, signed int line);
void fullscreen_message(char *message, signed int line);
char game_options(char **options, signed int offset);
int game_img(char *filename, signed int offset);

int launch_one();
void one_intro();
void scene_one();
