#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/stack.h"

void
exec_2_3(const char phrase[], char output[])
{
  int len = strlen(phrase);
  stack_t stack = stack_create(len);

  for (int i = 0; i <= len; i++)
  {
    /* Blank space or new line?
     * Then pop each item from stack. */
    if (phrase[i] == ' ' || phrase[i] == '\0') {
      while(!stack_is_empty(&stack)) {
        char ch = stack_pop(&stack);
        strncat(output, &ch, 1);
      }

      strncat(output, &phrase[i], 1);
    }

    /* Not a blank space? Then push it into
     * the stack. */
    else {
      stack_push(&stack, phrase[i]);
    }
  }
}
