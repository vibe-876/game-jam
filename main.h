void title_screen();

/* liquid to gold ratio, used in selling and buying
 * functions.
 */
#define GOLD_VALUE 5


void game_message(char *message, signed int line);
void fullscreen_message(char *message, signed int line);
char game_options(char **options, signed int offset);
int game_img(char *filename, signed int offset);


/* Okay, you might want to be a bit careful
 * with this, because there is a chance for
 * confusion between char and character, but
 * I can't think of a better name due to the
 * magic of sleep deprivation, so feel free to
 * change it.
 */
typedef struct character_struct {
  unsigned long gold; /* in grams */
  unsigned long liquid; /* ie, your liquid cash */
  unsigned char tax; /* Tax percent, no point in >1 byte */
} character;

void do_tax(character *person);
void sell_gold(character *person);


#define option_maker(name) \
  char name[2]; \
  name[1] = 0x0;

int launch_one();
void one_intro();
void scene_one();
void shop_scene_one(character *person);
