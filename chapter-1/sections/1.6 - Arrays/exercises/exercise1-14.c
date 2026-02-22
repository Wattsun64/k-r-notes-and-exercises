#include <_stdio.h>
#include <stdio.h>

/*
 * Exercise 1-14. Write a program to print a histogram of the frequences of
 * different characters in its input.
 */

#define CHAR_COUNTS 100

int main(void) {
  int c;
  int cchars[CHAR_COUNTS];

  for (int i = 0; i < CHAR_COUNTS; i++)
    cchars[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= '!' && c <= 127)
      ++cchars[c - '!'];
  }

  for (int i = 0; i < CHAR_COUNTS; i++) {
    if (cchars[i] > 0) {
      printf("%c ", i + '!');
      for (int j = 0; j < cchars[i]; j++)
        printf("=");
      printf("| %d\n", cchars[i]);
    }
  }

}
