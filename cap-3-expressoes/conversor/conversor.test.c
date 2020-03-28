#include <string.h>
#include "include/assert.h"
#include "conversor.h"

/**
 * Clear the string. Must be called before each test.
 */
#define PREPARE(actual) memset(actual, '\0', sizeof(actual))

int
main()
{
  char actual[100];

  PREPARE(actual);
  postfix_convert("2 * 3 + 8 / 4", actual);
  assert_string(
    "23*84/+",
    actual,
    "[2 * 3 + 8 / 4]"
  );

  PREPARE(actual);
  postfix_convert("(2 * 5) + (8 + 3)", actual);
  assert_string(
    "25*83++",
    actual,
    "[(2 * 5) + (8 + 3)]"
  );
}
