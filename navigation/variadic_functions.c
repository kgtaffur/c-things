#include <stdarg.h>
#include <stdio.h>

enum drink { MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE };

double price(enum drink d) {
  switch (d) {
  case MUDSLIDE:
    return 6.79;
  case FUZZY_NAVEL:
    return 5.31;
  case MONKEY_GLAND:
    return 4.82;
  case ZOMBIE:
    return 5.89;
  }
  return 0;
}

double total(int args, ...) {
  double total = 0;

  va_list args_list;
  va_start(args_list, args);

  int i;
  for (i = 0; i < args; i++) {
    total += price(va_arg(args_list, enum drink));
  }
  va_end(args_list);

  return total;
}

int main() {
  printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
  printf("Price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
  printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
  printf("Price is %.2f\n", total(1, ZOMBIE));
  return 0;
}
