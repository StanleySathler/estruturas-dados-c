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
  if (c == '(')
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
postfix_convert(const char infix[], char postfix[])
{
  int length = strlen(infix);
  char null_ch = '\0';
  char curr_ch = '\0';
  stack_t operators = stack_create(length);

  for (int i = 0; infix[i]; i++) {
    curr_ch = infix[i];

    /* Completely ignore this symbol. */
    if (curr_ch == ' ')
      continue;

    /* Opening parenthesis? Push into stack. */
    else if (curr_ch == '(')
      stack_push(&operators, curr_ch);

    /* Operand (0-9). */
    else if (isdigit(curr_ch)) {
      strncat(postfix, &curr_ch, 1);
    }

    /* Operator (+, -, /, *). */
    else if (is_operator(curr_ch)) {
      strncat(postfix, " ", 1);

      /* While item at the top has a higher priority,
       * move it from the stack to the postfix
       * expression.
       */
      while (
        !stack_is_empty(&operators) &&
        priority(curr_ch) <= priority(stack_top(&operators))
      ) {
        char operator = stack_pop(&operators);
        strncat(postfix, &operator, 1);
        strncat(postfix, " ", 1);
      }

      /* Then put the current operator in the
       * stack.
       */
      stack_push(&operators, curr_ch);
    }

    /* Closing parenthesis? */
    else if (curr_ch == ')') {

      /* Then move everything from stack until it finds
       * an opening parenthesis.
       */
      while (
        !stack_is_empty(&operators) &&
        stack_top(&operators) != '('
      ) {
        strncat(postfix, " ", 1);
        char operator = stack_pop(&operators);
        strncat(postfix, &operator, 1);
      }

      /* Remove '(' from stack. */
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
    strncat(postfix, " ", 1);
    char operator = stack_pop(&operators);
    strncat(postfix, &operator, 1);
  }

  /* Append '\0' to postfix to make it a real
   * string in C codes.
   */
  strncat(postfix, &null_ch, 1);
}

int
postfix_calculate(const char postfix[])
{
  int len = strlen(postfix);
  stack_t numbers = stack_create(len);

  for (int i = 0; postfix[i]; i++) {
    /* Digit? Convert number (using atof()) and push
     * into the stack.
     */
    if (isdigit(postfix[i])) {
      /* atof() receives the address of postfix[i]. */
      stack_push(&numbers, atof(&postfix[i]));

      /* Jump to after the whole number. */
      while (isdigit(postfix[i]))
        i++;
    }


    /* Operator? Pop two numbers from stack, calculate
     * them and then push the result into the stack again.
     */
    else if (is_operator(postfix[i])){
      int b = stack_pop(&numbers);
      int a = stack_pop(&numbers);
      stack_push(&numbers, calculate(a, postfix[i], b));
    }
  }

  /* Last item is always the final result. */
  int total = stack_pop(&numbers);

  stack_destroy(&numbers);
  return total;
}
