#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/stack.h"

int
main()
{
  char input[] = "{[()()]}";
  int is_balanced = 1;
  int len = strlen(input);
  stack_t stack = stack_create(len);

  for(int i = 0; i < len && is_balanced; i++)
  {
    /* Opening symbol. */
    if(input[i] == '[' || input[i] == '{' || input[i] == '(')
      stack_push(&stack, input[i]);

    /* Empty stack and closing symbol means
     * non-balanced.
     */
    else if (stack_is_empty(&stack))
      is_balanced = 0;

    else if (input[i] == ']') {
      if(stack_pop(&stack) != '[')
        is_balanced = 0;
    }

    else if(input[i] == '}') {
      if(stack_pop(&stack) != '{')
        is_balanced = 0;
    }

    else if(input[i] == ')') {
      if(stack_pop(&stack) != '(')
        is_balanced = 0;
    }
  }

  /* Stack not empty means non-balanced expression. */
  if (!stack_is_empty(&stack))
    is_balanced = 0;

  if (is_balanced)
    puts("Balanced.");
  else
    puts("Non-balanced.");

  return 0;
}
