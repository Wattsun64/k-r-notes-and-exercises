#include <stdio.h>

/*
 * Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input.
 */

#define IN  0
#define OUT 1

#define WORD_COUNTS 100

int main(void) {
  int c, state, lword;
  int lengths[WORD_COUNTS];

  for (int i = 0; i < WORD_COUNTS; i++)
    lengths[i] = 0;

  state = OUT;
  lword = 0;
  while ((c = getchar()) != EOF) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
      state = IN;
    else
      state = OUT;

    if (state == IN)
      ++lword;

    if (state == OUT && lword > 0) {
      ++lengths[lword - 1];
      lword = 0;
    }
  }

  for (int i = 0; i < WORD_COUNTS; i++) {
    if (lengths[i] > 0) {
      printf("%d ", i + 1);
      for (int j = 0; j < lengths[i]; j++)
        printf("=");
      printf("| %d\n", lengths[i]);
    }
  }

}
