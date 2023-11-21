#include <stdio.h>

int main() {
  const char *s = "this is a test string";
  s = "This is not a test string anymore";
  puts(s);
  printf("%c\n", *s);
  printf("%s\n", &s);

  int num = 2;
  int *n = &num;
  printf("%i\n", *n);
  return 0;
}
