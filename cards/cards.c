#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char card_name[3];
  bool running = true;
  int count = 0;

  while (running) {
    puts("Enter the card name: ");
    scanf("%2s", card_name);
    int val = 0;
    switch (card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      running = false;
      break;
    default:
      val = atoi(card_name);
      if (val < 1 || val > 10) {
        printf("The card name cannot be %i\n", val);
        continue;
      }
      break;
    }
    // printf("The card value is: %i\n", val);

    /* Check if the value is 3 to 6 */
    if (val >= 3 && val <= 6) {
      puts("Count has gone up");
      count++;
      /* Otherwise check if the card was 10, J, Q or K */
    } else if (val == 10) {
      puts("Count has gone down");
      count--;
    }
    printf("The counting is: %i\n", count);
  }
  return 0;
}
