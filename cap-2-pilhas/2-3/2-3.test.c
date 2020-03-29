#include <string.h>
#include "include/assert.h"
#include "2-3.h"

/**
 * Clear the string. Must be called before each test.
 */
#define PREPARE(actual) memset(actual, '\0', sizeof(actual))

void
assert(const char* expected, char* actual, const char* message)
{
  assert_string(expected, actual, message);
  PREPARE(actual);
}

int
main()
{
  char actual[100];

  exec_2_3("apenas um teste", actual);
  assert(
    "sanepa mu etset",
    actual,
    "[apenas um teste]"
  );
}
