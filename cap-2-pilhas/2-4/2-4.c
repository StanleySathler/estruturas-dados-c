#include <stdio.h>
#include "include/stack.h"

void
exec_2_4(const int input[], int output[], int length)
{
  stack_t a = stack_create(length);
  stack_t b = stack_create(length);

  for (int i = 0; i < length; i++) {

    /* If stack A is either empty or has a bigger number at
     * its top, we just push the current number (which is smaller).
     */
    if (stack_is_empty(&a) || input[i] < stack_top(&a))
      stack_push(&a, input[i]);

    /* If the current number is higher than the A's top,
     * then we need to find out which index to push the
     * current number into A.
     */
    else {
      /* So we move every smaller number from A to B. */
      while (!stack_is_empty(&a) && stack_top(&a) < input[i] )
        stack_push(&b, stack_pop(&a));

      /* Then we push the current number into A. */
      stack_push(&a, input[i]);

      /* Then we move everything from B to A again. */
      while(!stack_is_empty(&b))
        stack_push(&a, stack_pop(&b));
    }
  }

  /* Move items from stack to output. */
  for (int j = 0; !stack_is_empty(&a); j++)
    output[j] = stack_pop(&a);
}
