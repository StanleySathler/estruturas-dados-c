#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/stack.h"

#define MAX 25

int
main()
{
  char phrase[MAX];
  stack_t stack = stack_create(MAX);

  printf("Phrase: ");
  fgets(phrase, sizeof(phrase), stdin);

  for (int i = 0; i <= strlen(phrase); i++)
  {
    /* Blank space or new line?
     * Then pop each item from stack. */
    if (phrase[i] == ' ' || phrase[i] == '\n') {
      while(!stack_is_empty(&stack))
        printf("%c", stack_pop(&stack));

      printf("%c", phrase[i]);
    }

    /* Not a blank space? Then push it into
     * the stack. */
    else {
      stack_push(&stack, phrase[i]);
    }
  }

  return 0;
}
