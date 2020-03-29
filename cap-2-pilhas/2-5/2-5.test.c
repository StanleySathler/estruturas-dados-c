#include <string.h>
#include "include/assert.h"
#include "2-5.h"

int
main()
{
  int actual;

  actual = exec_2_5("{[()()]}");
  assert_int(1, actual, "[ {[()()]} ]: Should be balanced");

  actual = exec_2_5("[][]{}");
  assert_int(1, actual, "[ [][]{} ]: Should be balanced");

  actual = exec_2_5("");
  assert_int(1, actual, "[ ]: Should be balanced");

  actual = exec_2_5("{()");
  assert_int(0, actual, "[ {() ]: Should not be balanced");

  actual = exec_2_5("{()()]");
  assert_int(0, actual, "[ {()()] ]: Should not be balanced");
}
