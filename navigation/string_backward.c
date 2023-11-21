#include <stdio.h>
#include <string.h>

/* Function to reverse a string */
void print_reverse(char *str) {
  // length of string parameter
  size_t len = strlen(str);
  // new string containing the last character of str
  // important to note that str is a pointer to
  // the first element of that array
  char *reversed = str + len - 1;

  // reversed should be >= str
  // reversed is an address to the last char in str
  // so if reversed >= str means that it should iterate
  // until reversed address is less than str
  // so the first str array char
  while (reversed >= str) {
    // prints char by char each iteration
    printf("%c", *reversed);

    // pointer arithmetic
    // last str array address - 1 is the previous char
    reversed = reversed - 1;
  }
  // newline at the end of the string
  puts("");
}

int main() {
  // Function call
  print_reverse("This text should be reversed");
  return 0;
}
