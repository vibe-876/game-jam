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

void doTax(character *person);
