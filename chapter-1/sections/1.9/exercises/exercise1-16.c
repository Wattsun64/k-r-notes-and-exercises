#include <stdio.h>

#define MAXLINE 1000
#define REQUIRED 375

/*
 * Exercise 1-16. Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitraily long input lines,
 * and as much as possible of the text
 */

int gline(char line[], int maxline);
void copy(char to[], char from[]);
void printl(char line[], int length);

int main(void) {
  int len, max, base;
  char line[MAXLINE], longest[MAXLINE];

  max = 0;
  while ((len = gline(line, MAXLINE)) > 0) {
    max = len;
    copy(longest, line);

    if (max > REQUIRED)
      printl(longest, len);
  }

  return 0;
}

/* gline: read a line int s, return length */
int gline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}

void printl(char line[], int length) {
  printf("length: %d\n%s\n", length, line);
}
