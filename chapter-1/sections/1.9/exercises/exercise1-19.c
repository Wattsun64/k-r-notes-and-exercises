#include <stdio.h>
#include <stdlib.h>

/*
 * Exercise 1-19. Write a function `reverse(s)` that reverses the
 * character string s. Use it to write a program that reverses a line
 * at a time.
 */

#define CHARS_MAX 1000

#define IN  0
#define OUT 1

void zinit(char s[], int size) {
  for (int i = 0; i < size; i++)
    s[i] = 0;
}

int extract(char s[]) {
  int c, size;
  size = 0;
  while ((c = getchar()) != EOF)
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')
      s[size++] = c;
  s[size] = '\0';
  return size;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}

int gline(char dest[], int limit) {
  int i, c;
  for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; i++)
    dest[i] = c;

  if (c == '\n') {
    dest[i] = '\n';
    ++i;
  }

  dest[i] = '\0';

  return i;
}

void reverse(char s[], int size) {
  int limit = (size - 1) / 2;
  int i;
  for (i = 0; i <= limit; i++) {
    char c1, c2;
    int curr_idx, swap_idx;
    curr_idx = i;
    swap_idx = size - i - 1;

    c1 = s[curr_idx];
    c2 = s[swap_idx];

    s[curr_idx] = c2;
    s[swap_idx] = c1;
  }
}

int main(void) {
  char chars[CHARS_MAX];
  char dest[CHARS_MAX];
  int c, i, state, limit, wlimit, length, max;

  zinit(chars, CHARS_MAX);
  zinit(dest, CHARS_MAX);

  while ((length = gline(chars, CHARS_MAX)) > 0) {
    max = length;
    copy(dest, chars);
    reverse(dest, max);
    printf("%s", dest);
  }

  return EXIT_SUCCESS;
}
