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
  printf("\f");
}
