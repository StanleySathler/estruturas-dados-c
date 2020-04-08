#include "include/assert.h"
#include "coloracao.h"

int
main()
{
  int image[HEIGHT][WIDTH] = {
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

  flood_fill(image, 2, 4, 5);
  assert_int(5, image[2][4], "[flood_fill]: Should paint (2-4)");

  assert_int(5, image[1][4], "[flood_fill]: Should paint (1-4)");
  assert_int(5, image[2][3], "[flood_fill]: Should paint (2-3)");
  assert_int(5, image[2][5], "[flood_fill]: Should paint (2-5)");

  assert_int(5, image[3][2], "[flood_fill]: Should paint (3-2)");
  assert_int(5, image[3][3], "[flood_fill]: Should paint (3-3)");
  assert_int(5, image[3][4], "[flood_fill]: Should paint (3-4)");
  assert_int(5, image[3][5], "[flood_fill]: Should paint (3-5)");
  assert_int(5, image[3][6], "[flood_fill]: Should paint (3-6)");

  assert_int(5, image[4][1], "[flood_fill]: Should paint (4-1)");
  assert_int(5, image[4][2], "[flood_fill]: Should paint (4-2)");
  assert_int(5, image[4][3], "[flood_fill]: Should paint (4-3)");
  assert_int(5, image[4][4], "[flood_fill]: Should paint (4-4)");
  assert_int(5, image[4][5], "[flood_fill]: Should paint (4-5)");
  assert_int(5, image[4][6], "[flood_fill]: Should paint (4-6)");
  assert_int(5, image[4][7], "[flood_fill]: Should paint (4-7)");

  assert_int(0, image[0][4], "[flood_fill]: Should keep (0-4)");
  assert_int(0, image[1][3], "[flood_fill]: Should keep (1-3)");
  assert_int(2, image[5][2], "[flood_fill]: Should keep (5-2)");
  assert_int(2, image[5][6], "[flood_fill]: Should keep (5-6)");

  return 0;
}
