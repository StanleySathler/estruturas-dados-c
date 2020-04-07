#include "include/assert.h"
#include "4-3.h"

int
main()
{
  int actual;

  actual = is_palindrome("amor e roma");
  assert_int(1, actual, "[amor e roma]: Should be true");

  actual = is_palindrome("Amor e Roma");
  assert_int(1, actual, "[Amor e Roma]: Should be true");

  actual = is_palindrome("Amor e Amor");
  assert_int(0, actual, "[Amor e Amor]: Should be false");
}
