#include "include/assert.h"
#include "6-1.h"

int
main()
{
  double actual = 0;

  actual = exec_6_1(2, 6);
  assert_double(actual, 64, "[2 ^ 6]");

  actual = exec_6_1(5, 5);
  assert_double(actual, 3125, "[5 ^ 5]");

  actual = exec_6_1(3, 1);
  assert_double(actual, 3, "[3 ^ 1]");

  actual = exec_6_1(3, 0);
  assert_double(actual, 1, "[3 ^ 0]");
}
