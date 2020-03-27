#include <stdio.h>
#include "../libs/stack.h"

int
main()
{
  char list[] = { '9', '1', '6', '7', '4', '8' };
  int list_len = (int)(sizeof(list) / sizeof(char));
  stack_t a = stack_create(list_len);
  stack_t b = stack_create(list_len);

  for (int i = 0; i < list_len; i++) {

    /* If stack A is either empty or has a bigger number at
     * its top, we just push the current number (which is smaller).
     */
    if (stack_is_empty(&a) || list[i] < stack_top(&a))
      stack_push(&a, list[i]);

    /* If the current number is higher than the A's top,
     * then we need to find out which index to push the
     * current number into A.
     */
    else {
      /* So we move every smaller number from A to B. */
      while (!stack_is_empty(&a) && stack_top(&a) < list[i] )
        stack_push(&b, stack_pop(&a));

      /* Then we push the current number into A. */
      stack_push(&a, list[i]);

      /* Then we move everything from B to A again. */
      while(!stack_is_empty(&b))
        stack_push(&a, stack_pop(&b));
    }
  }

  /* Print the ordered sequence. */
  while (!stack_is_empty(&a))
    printf("%c ", stack_pop(&a));

  putchar('\n');
  return 0;
}
