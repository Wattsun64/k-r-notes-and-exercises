#include <stdio.h>

/*
 * Exercise 1-2. Experiment to find out what happens when printf's argument
 * string contains \c, where c is some character not listed in:
 *  - \n
 *  - \t
 *  - \b
 *  - \\
 *  - \"
 */

int main(void) {
  printf("\a");
  printf("\e");
  printf("\v");

  // Error: No following hex digits
  // printf("\u");

  // Unknown escape sequences
  printf("\h");
  printf("\p");
  printf("\y");
  printf("\m");
  printf("\w");
  printf("\q");
  printf("\m");
  printf("\9");
  printf("\l");
}
