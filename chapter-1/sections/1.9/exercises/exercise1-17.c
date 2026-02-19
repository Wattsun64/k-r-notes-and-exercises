#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Exercise 1-17. Write a program to print all input lines
 * that are longer than 80 characters.
 */

#define INITIALIZED 1
#define SET 2
#define RESET 3

int zinit(char s[], int size) {
  for (int i = 0; i < size; i++)
    s[i] = 0;
  return INITIALIZED;
}

int getlines(char s[]) {
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF)
    if ((c >= ' ' && c <= '~') || c == '\n') {
      s[i] = c;
      ++i;
    }
  s[i] = '\0';
  return i;
}

int copy(char src[], char dest[], int pos, int size) {
  int i;
  for (i = 0; i < size; i++)
    dest[i] = src[pos++];
  dest[i+1] = '\0';
  return SET;
}

int main(void) {
  char chars[1000], dest[1000];
  int c, i, limit, length, set, count;

  zinit(chars, CHAR_MAX);
  zinit(dest, CHAR_MAX);

  limit = getlines(chars);
  count = set = RESET;
  length = i = 0;
  while ((c = chars[++i]) != '\0') {
    if (c == '\n') {
      set = copy(chars, dest, i-length, length);
      count = length;
      length = 0;
    }
    else {
      length++;
    }

    if (set == SET && count > 80) {
      printf("%s\n", dest);
      count = set = RESET;
    }
  }
  return EXIT_SUCCESS;
}
