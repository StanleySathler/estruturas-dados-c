#include <string.h>
#include "include/assert.h"
#include "conversor.h"

#define MAX 100
#define AFTER_EACH(actual) memset(actual, '\0', MAX)

void assert(const char expected[], char actual[], const char message[])
{
  assert_string(expected, actual, message);
  AFTER_EACH(actual);
}

int
main()
{
  char actual[MAX];

  postfix_convert("2 * 3 + 8 / 4", actual);
  assert("23*84/+", actual, "[2 * 3 + 8 / 4]");

  postfix_convert("(2 * 5) + (8 + 3)", actual);
  assert("25*83++", actual, "[(2 * 5) + (8 + 3)]");

  postfix_convert("2 * 5 + 3 / 2 + 1", actual);
  assert("25*32/+1+", actual, "[2 * 5 + 3 / 2 + 1]");

  postfix_convert("2 * (3 + 1 * 2)", actual);
  assert("2312*+*", actual, "[2 * (3 + 1 * 2)]");

  postfix_convert("2 * (3 * 2 + 4 * 7)", actual);
  assert("232*47*+*", actual, "[2 * (3 * 2 + 4 * 7)]");
}
