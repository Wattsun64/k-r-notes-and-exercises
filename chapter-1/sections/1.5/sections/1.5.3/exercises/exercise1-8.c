#include <stdio.h>

/*
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 */

int main(void) {
  int c, cc;

  cc = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\n')
      ++cc;
  printf("%d\n", cc);
}
