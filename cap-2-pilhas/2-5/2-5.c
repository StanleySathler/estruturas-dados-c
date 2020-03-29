#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/stack.h"

int
exec_2_5(char input[])
{
  int len = strlen(input);
  stack_t stack = stack_create(len);

  for(int i = 0; i < len; i++)
  {
    /* Opening symbol. */
    if(input[i] == '[' || input[i] == '{' || input[i] == '(')
      stack_push(&stack, input[i]);

    /* Empty stack and closing symbol means
     * non-balanced.
     */
    else if (stack_is_empty(&stack))
      return 0;

    else if (input[i] == ']') {
      if(stack_pop(&stack) != '[')
        return 0;
    }

    else if(input[i] == '}') {
      if(stack_pop(&stack) != '{')
        return 0;
    }

    else if(input[i] == ')') {
      if(stack_pop(&stack) != '(')
        return 0;
    }
  }

  /* Stack not empty means non-balanced expression. */
  if (!stack_is_empty(&stack))
    return 0;

  return 1;
}
