#include "include/assert.h"
#include "../drawer/drawer.h"
#include "5-3.h"

int
main()
{
  Image img;

  img = exec_5_3("image.txt");
  assert_int(7, img->pixels[4 * img->width + 4], "Should load content");
  assert_int(9, img->width, "Should set width");
  assert_int(9, img->height, "Should set height");
}
