#include <stdio.h>

/*
 * Exercise 1-9. Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */

int main(void) {
  int c, bc;

  bc = 0;
  while ((c = getchar()) != EOF) {
    bc = (c != ' ') ? 0 : bc + 1;
    if (bc <= 1)
      putchar(c);
  }
}
