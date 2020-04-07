#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "include/queue.h"
#include "include/stack.h"

int
is_palindrome(char expression[])
{
  int len = strlen(expression);
  char curr_ch;
  stack_t s = stack_create(len);
  queue_t q = queue_create(len);

  for (int i = 0; expression[i]; i++) {
    curr_ch = expression[i];
    stack_push(&s, toupper(curr_ch));
    queue_add(&q, toupper(curr_ch));
  }

  while (!queue_empty(&q)) {
    if (queue_consume(&q) != stack_pop(&s))
      return 0;
  }

  return 1;
}
