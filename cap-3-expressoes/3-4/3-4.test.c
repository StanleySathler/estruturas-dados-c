#include <stdio.h>
#include <string.h>
#include "include/assert.h"
#include "3-4.h"

int
main()
{
  char actual[100];

  memset(actual, '\0', 100);
  exec_3_4("((A * B) + (C / D))", actual);
  assert_string("+ * A B / C D", actual, "[((A * B) + (C / D))]");
}
