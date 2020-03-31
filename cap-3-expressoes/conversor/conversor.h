#pragma once

/**
 * Convert an infix expression into a postfix one.
 */
void
postfix_convert(const char infix[], char postfix[]);

/**
 * Calculate a postfix expression.
 */
int
postfix_calculate(const char postfix[]);
