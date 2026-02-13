#include <stdio.h>

/*
 * Exercise 1-12. Write a program that prints its input one word per line.
 */

#define IN 1
#define OUT 0

int main(void) {
  int c, ec, state;

  ec = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t' || c == '\b') {
      state = OUT;
      ++ec;
    }
    else {
      state = IN;
      ec = 0;
    }

    if (ec == 1)
      printf("\n");

    if (state == IN)
      putchar(c);

  }

}
