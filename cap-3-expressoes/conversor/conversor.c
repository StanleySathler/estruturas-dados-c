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
postfix_convert(const char infix[], char postfix[])
{
  int length = strlen(infix);
  char null_ch = '\0';
  char curr_ch = '\0';
  stack_t operators = stack_create(length);

  for (int i = 0; infix[i]; i++) {
    curr_ch = infix[i];

    /* Completely ignore this symbol. */
    if (curr_ch == '(' || curr_ch == ' ')
      continue;

    /* Operand (0-9). */
    else if (isdigit(curr_ch)) {
      strncat(postfix, &curr_ch, 1);
    }

    /* Operator (+, -, /, *). */
    else if (is_operator(curr_ch)) {

      /* If current operator has a lower priority, move
       * the higher operator from the stack to the postfix.
       */
      if (
        !stack_is_empty(&operators) &&
        priority(curr_ch) < priority(stack_top(&operators))
      ) {
        char operator = stack_pop(&operators);
        strncat(postfix, &operator, 1);
      }

      stack_push(&operators, curr_ch);
    }

    /* Closing parenthesis must be replaced
     * by the last operator seen.
     */
    else if (curr_ch == ')') {
      char operator = stack_pop(&operators);
      strncat(postfix, &operator, 1);
    }

    else {
      fprintf(stderr, "Invalid symbol: %c \n", curr_ch);
    }
  }

  /* If stack is not empty, move all operators
   * to the postfix expression.
   */
  while (!stack_is_empty(&operators)) {
    char operator = stack_pop(&operators);
    strncat(postfix, &operator, 1);
  }

  /* Append '\0' to postfix to make it a real
   * string in C codes.
   */
  strncat(postfix, &null_ch, 1);

  return 0;
}
