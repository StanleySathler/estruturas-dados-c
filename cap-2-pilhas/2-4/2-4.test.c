#include <string.h>
#include "include/assert.h"
#include "2-4.h"

int
main()
{
  int actual[100];

  exec_2_4((int[]){9, 2, 6, 3}, actual, 4);
  assert_int(actual[0], 2, "[9, 2, 6, 3] 1st item should be 2");
  assert_int(actual[1], 3, "[9, 2, 6, 3] 2nd item should be 3");
  assert_int(actual[2], 6, "[9, 2, 6, 3] 3rd item should be 6");
  assert_int(actual[3], 9, "[9, 2, 6, 3] 4th item should be 9");
}
