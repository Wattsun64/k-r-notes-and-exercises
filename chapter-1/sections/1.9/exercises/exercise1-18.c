#include <stdio.h>

/*
 * Exercise 1-18. Write a program to remove trailing blanks and tabs
 * from each line of input, and to delete entirely blank lines.
 */

#define MAXLINE 1000
#define INITIALIZED 1

int zinit(char s[], int size) {
  for (int i = 0; i < size; i++)
    s[i] = 0;
  return INITIALIZED;
}

int gline(char s[], int limit) {
  int i, c;
  for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

int sanitize(char to[], char from[]) {
  int i, j, c, buffer, spaces, next;
  i = j = 0;
  while ((c = from[i++]) != '\n') {
    if (c == ' ' || c == '\t')
      ++spaces;

    if ((c >= '!' && c <= '~') || c == '\n') {
      to[j++] = c;
      spaces = 0;
    }

    if (spaces == 1)
      to[j++] = ' ';
  }

  if (j > 0)
    to[j] = '\0';

  return j;
}

int main(void) {
  char chars[1000], dest[1000];
  int line, limit, nlimit;

  zinit(chars, MAXLINE);
  zinit(dest, MAXLINE);

  nlimit = 0;

  while ((line = gline(chars, MAXLINE)) > 0) {
    nlimit = sanitize(dest, chars);
    if (nlimit > 0)
      printf("%s\n", dest);
  }

  return 0;
}
