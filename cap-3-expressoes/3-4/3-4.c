#include <stdio.h>
#include <stdlib.h>
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
  if (c == ')')
    return 0;
  else if (c == '+' || c == '-')
    return 1;
  else if (c == '*' || c == '/')
    return 2;
}

static int
calculate(char a, char opr, char b)
{
  if (opr == '+')
    return a + b;
  else if (opr == '-')
    return a - b;
  else if (opr == '*')
    return a * b;
  else if (opr == '/')
    return a / b;
}

void
exec_3_4(const char infix[], char prefix[])
{
  int length = strlen(infix);
  char null_ch = '\0';
  char curr_ch = '\0';
  stack_t operators = stack_create(length);

  /* For each item, in reverse order. */
  for (int i = (length - 1); i >= 0; i--) {
    curr_ch = infix[i];

    /* Completely ignore this symbol. */
    if (curr_ch == ' ')
      continue;

    /* Closing parenthesis? Push into stack. */
    else if (curr_ch == ')')
      stack_push(&operators, curr_ch);

    /* Operand (A-Z). */
    else if (isalpha(curr_ch)) {
      strncat(prefix, &curr_ch, 1);
    }

    /* Operator (+, -, /, *). */
    else if (is_operator(curr_ch)) {
      strncat(prefix, " ", 1);

      /* While item at the top has a higher priority,
       * move it from the stack to the postfix
       * expression.
       */
      while (
        !stack_is_empty(&operators) &&
        priority(curr_ch) <= priority(stack_top(&operators))
      ) {
        char operator = stack_pop(&operators);
        strncat(prefix, &operator, 1);
        strncat(prefix, " ", 1);
      }

      /* Then put the current operator in the
       * stack.
       */
      stack_push(&operators, curr_ch);
    }

    /* Opening parenthesis? */
    else if (curr_ch == '(') {

      /* Then move everything from stack until it finds
       * an opening parenthesis.
       */
      while (
        !stack_is_empty(&operators) &&
        stack_top(&operators) != ')'
      ) {
        strncat(prefix, " ", 1);
        char operator = stack_pop(&operators);
        strncat(prefix, &operator, 1);
      }

      /* Remove ')' from stack. */
      stack_pop(&operators);
    }

    else {
      fprintf(stderr, "Invalid symbol: %c \n", curr_ch);
    }
  }

  /* If stack is not empty, move all operators
   * to the postfix expression.
   */
  while (!stack_is_empty(&operators)) {
    strncat(prefix, " ", 1);
    char operator = stack_pop(&operators);
    strncat(prefix, &operator, 1);
  }

  /* Append '\0' to postfix to make it a real
   * string in C codes.
   */
  strncat(prefix, &null_ch, 1);

  /* Reverse prefix expression. */
  int pref_len = strlen(prefix);
  for (int i = 0, j = (pref_len - 1); i < (pref_len / 2); i++, j--) {
    char aux = prefix[i];
    prefix[i] = prefix[j];
    prefix[j] = aux;
  }
}
