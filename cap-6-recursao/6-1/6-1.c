#include <stdio.h>

double
exec_6_1(double x, int n)
{
  if (n == 0)
    return 1;
  else if (n == 1)
    return x;
  else
    return x * exec_6_1(x, n - 1);
}
