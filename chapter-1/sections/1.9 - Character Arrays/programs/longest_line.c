#include <stdio.h>

#define MAXLINE 1000

int gline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
  int len, max;
  char line[MAXLINE], longest[MAXLINE];

  max = 0;
  while ((len = gline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }

  if (max > 0)
    printf("%s", longest);

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
