#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "include/stack.h"

static int
is_operator(char c)
{
  return (
    c == '+' ||
    c == '-' ||
    c == '*' ||
    c == '/'
  );
}

static int
priority(char c)
{
  if (c == '+' || c == '-')
    return 1;
  else if (c == '*' || c == '/')
    return 2;
}

int
main()
{
  char infix[] = "2 * 3 + 2 / 4 - 1 * 2";
  int infix_len = strlen(infix);
  char postfix[infix_len + 1]; // +1 for '\0'
  char curr_c;
  stack_t operators = stack_create(infix_len);

  for (int i = 0; infix[i]; i++) {
    curr_c = infix[i];

    /* Completely ignore this symbol. */
    if (curr_c == '(' || curr_c == ' ')
      continue;

    /* Operand (0-9). */
    else if (isdigit(curr_c)) {
      strncat(postfix, &curr_c, 1);
    }

    /* Operator (+, -, /, *). */
    else if (is_operator(curr_c)) {

      /* If current operator has a lower priority, move
       * the higher operator from the stack to the postfix.
       */
      if (
        !stack_is_empty(&operators) &&
        priority(curr_c) < priority(stack_top(&operators))
      ) {
        char operator = stack_pop(&operators);
        strncat(postfix, &operator, 1);
      }

      stack_push(&operators, curr_c);
    }

    /* Closing parenthesis must be replaced
     * by the last operator seen.
     */
    else if (curr_c == ')') {
      char operator = stack_pop(&operators);
      strncat(postfix, &operator, 1);
    }

    else {
      fprintf(stderr, "Invalid symbol: %c \n", curr_c);
    }
  }

  /* If stack is not empty, move all operators
   * to the postfix expression.
   */
  while (!stack_is_empty(&operators)) {
    char operator = stack_pop(&operators);
    strncat(postfix, &operator, 1);
  }

  /* Print postfix expression. */
  for (int i = 0; i < strlen(postfix); i++)
    putchar(postfix[i]);
  putchar('\n');

  return 0;
}
