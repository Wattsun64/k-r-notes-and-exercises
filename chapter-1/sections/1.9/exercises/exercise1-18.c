#include <stdio.h>

/*
 * Exercise 1-18. Write a program to remove trailing blanks and tabs
 * from each line of input, and to delete entirely blank lines.
 */

#define MAXLINE 1000

void zinit(char s[], int limit) {
  for (int i = 0; i < limit; i++)
    s[i] = 0;
}

int gline(char s[], int limit) {
  int i, c;

  for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';

  return i;
}

int remove_trail(char s[], int size) {
  int i, c;

  i = 0;
  while ((c = s[--size]) > 0)
    if (c >= '!' && c <= '~')
      break;
  if (size > 0)
    s[++size] = '\0';

  return size;
}

int main(void) {
  char input[MAXLINE];
  int line, nline;
  zinit(input, MAXLINE);
  while ((line = gline(input, MAXLINE)) > 0) {
    nline = remove_trail(input, line);
    if (nline > 0)
      printf("%s\n", input);
  }
  return 0;
}
