#include <stdio.h>

void go_south_east(int *latitude, int *longitude) {
  printf("%p, %p\n", latitude, longitude);
  // latitude -= 1;
  // longitude += 1;
  printf("%i, %i\n", *latitude, **&longitude);
}

void testing(char str[], int n[]) {
  printf("%i\n", sizeof(str)); // bytes (decay)
  printf("%s\n", str);         // content
  printf("%s\n", &str); // &str and str are not the same thing here because it's
                        // a function parameter (pointer)
  printf("%c\n", *str); // first element of the array
  printf("%c\n", str[0]); // first element of the array

  puts(str + 10); // prints from the 10th character

  printf("Second number: %i\n", n[1]);
  printf("Second number: %i\n", *(n + 1));
}

int main() {
  int latitude = 32;
  int longitude = -64;
  go_south_east(&latitude, &longitude);
  printf("Avast! Now at: [%i, %i]\n", latitude, longitude);

  char text[] = "This is a character array";
  puts("MAIN");
  printf("%i\n", sizeof(text)); // bytes
  printf("%s\n", text);         // content
  printf("%s\n", &text);        // &text and text are the same thing
  printf("%c\n", *text);        // first element of the array
  printf("%c\n", text[0]);      // first element of the array

  // 1 CHAR IS 1 BYTE OF MEMORY
  // INT IS 4 BYTES OF MEMORY
  puts(text + 10); // prints from the 10th character
  // this is why arrays start at 0
  int numbers[] = {1, 2, 3};
  printf("Second number: %i\n", numbers[1]);
  printf("Second number: %i\n", *(numbers + 1));
  puts("FUNCTION");
  testing(text, numbers);
  return 0;
}
