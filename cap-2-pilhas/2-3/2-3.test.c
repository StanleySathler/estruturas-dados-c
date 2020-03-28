#include <string.h>
#include "include/assert.h"
#include "2-3.h"

/**
 * Clear the string. Must be called before each test.
 */
#define PREPARE(actual) memset(actual, '\0', sizeof(actual))

int
main()
{
  char actual[100];

  PREPARE(actual);
  exec_2_3("apenas um teste", actual);
  assert_string(
    "sanepa mu etset",
    actual,
    "[apenas um teste]"
  );
}
