#include <stdio.h>

/*
 * Exercise 1-6. Verify that the expression `getchar() != EOF` is 0 or 1
 */

int main(void) {
  int c;
  while ((c = getchar() != EOF)) {
    if (c == 0)
      putchar('0');
    else
      putchar('1');
  }
}
