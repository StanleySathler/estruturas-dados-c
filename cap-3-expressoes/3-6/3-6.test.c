#include <stdio.h>
#include <string.h>
#include "include/assert.h"
#include "3-6.h"

int
main()
{
  char actual[100];
  int actual_total;

  memset(actual, '\0', 100);
  exec_3_6_a("(V & V) | (V & F)", actual);
  assert_string("V V & V F & |", actual, "[exec_3_6_a]: (V & V) | (V & F)");

  memset(actual, '\0', 100);
  exec_3_6_a("((V | F) & (F | (F & F)))", actual);
  assert_string("V F | F F F & | &", actual, "[exec_3_6_a]: ((V | F) & (F | (F & F)))");

  actual_total = exec_3_6_b("V V & V F & |");
  assert_int(1, actual_total, "[exec_3_6_b]: V V & V F & |");

  actual_total = exec_3_6_b("V F | F F F & | &");
  assert_int(0, actual_total, "[exec_3_6_b]: V F | F F F & | &");

  actual_total = exec_3_6_b("V ~ V &");
  assert_int(0, actual_total, "[exec_3_6_b]: V ~ V &");
}
