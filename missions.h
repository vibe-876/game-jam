/* Is there even a point to this
 * being here, or should I throw it
 * into another file?
 */
#define option_maker(name) \
  char name[2]; \
  name[1] = 0x0;
