#include "include/assert.h"
#include "drawer.h"

#define WIDTH 9
#define HEIGHT 9

int
main()
{
  Image img;
  int pixels[HEIGHT][WIDTH] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
    { 0, 0, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 2, 0, 0, 0, 2, 0, 0 },
    { 0, 0, 2, 0, 0, 0, 2, 0, 0 },
    { 0, 0, 2, 2, 2, 2, 2, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  };

  img = drawer_image_create((int*)pixels, 9, 9);
  assert_int(0, img->pixels[0 * WIDTH + 0], "[drawer_image_create]: Should copy pixel (0,0)");
  assert_int(1, img->pixels[1 * WIDTH + 4], "[drawer_image_create]: Should copy pixel (1,4)");
  assert_int(2, img->pixels[7 * WIDTH + 6], "[drawer_image_create]: Should copy pixel (1,4)");
  drawer_image_destroy(img);

  img = drawer_image_create((int*)pixels, 9, 9);
  flood_fill(img, 2, 4, 5);
  assert_int(5, img->pixels[2 * WIDTH + 4], "[flood_fill]: Should paint (2-4)");

  assert_int(5, img->pixels[1 * WIDTH + 4], "[flood_fill]: Should paint (1-4)");
  assert_int(5, img->pixels[2 * WIDTH + 3], "[flood_fill]: Should paint (2-3)");
  assert_int(5, img->pixels[2 * WIDTH + 5], "[flood_fill]: Should paint (2-5)");

  assert_int(5, img->pixels[3 * WIDTH + 2], "[flood_fill]: Should paint (3-2)");
  assert_int(5, img->pixels[3 * WIDTH + 3], "[flood_fill]: Should paint (3-3)");
  assert_int(5, img->pixels[3 * WIDTH + 4], "[flood_fill]: Should paint (3-4)");
  assert_int(5, img->pixels[3 * WIDTH + 5], "[flood_fill]: Should paint (3-5)");
  assert_int(5, img->pixels[3 * WIDTH + 6], "[flood_fill]: Should paint (3-6)");

  assert_int(5, img->pixels[4 * WIDTH + 1], "[flood_fill]: Should paint (4-1)");
  assert_int(5, img->pixels[4 * WIDTH + 2], "[flood_fill]: Should paint (4-2)");
  assert_int(5, img->pixels[4 * WIDTH + 3], "[flood_fill]: Should paint (4-3)");
  assert_int(5, img->pixels[4 * WIDTH + 4], "[flood_fill]: Should paint (4-4)");
  assert_int(5, img->pixels[4 * WIDTH + 5], "[flood_fill]: Should paint (4-5)");
  assert_int(5, img->pixels[4 * WIDTH + 6], "[flood_fill]: Should paint (4-6)");
  assert_int(5, img->pixels[4 * WIDTH + 7], "[flood_fill]: Should paint (4-7)");

  assert_int(0, img->pixels[0 * WIDTH + 4], "[flood_fill]: Should keep (0-4)");
  assert_int(0, img->pixels[1 * WIDTH + 3], "[flood_fill]: Should keep (1-3)");
  assert_int(2, img->pixels[5 * WIDTH + 2], "[flood_fill]: Should keep (5-2)");
  assert_int(2, img->pixels[5 * WIDTH + 6], "[flood_fill]: Should keep (5-6)");
  drawer_image_destroy(img);

  int pixels2[HEIGHT][WIDTH] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 1, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 1, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
    { 0, 0, 1, 0, 1, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 1, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  };

  img = drawer_image_create((int*)pixels2, 9, 9);
  flood_fill(img, 4, 4, 5);
  assert_int(5, img->pixels[1 * WIDTH + 1], "[flood_fill]: Should paint (1,1)");
  assert_int(5, img->pixels[7 * WIDTH + 1], "[flood_fill]: Should paint (7,1)");
  assert_int(5, img->pixels[7 * WIDTH + 7], "[flood_fill]: Should paint (7,7)");
  assert_int(5, img->pixels[1 * WIDTH + 7], "[flood_fill]: Should paint (1,7)");

  return 0;
}
