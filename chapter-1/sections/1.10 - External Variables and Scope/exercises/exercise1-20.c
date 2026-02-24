#include <stdio.h>

/*
 * Exercise 1-20. Write a program `detab` that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop. Assume a
 * fixed set of tab stops, say every n columns. Should n be a variable or a
 * symbolic parameter?
 */

#define MAXLINE 1000
#define TABSTOP 8

void cinit(char s[], int limit) {
  for (int i = 0; i < limit; i++)
    s[i] = 0;
}

int extract(char s[], int limit) {
  int i, c;
  for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';

  return i;
}

int insert_tab_stop(char in[], int pos) {
  int stop = (pos / TABSTOP + 1) * TABSTOP;
  while (pos < stop)
    in[pos++] = ' ';

  return pos;
}

void adjust(char out[], char in[]) {
  int i, j, c;
  i = j = 0;
  while ((c = in[i++]) != '\0') {
    if (c == '\t')
      j = insert_tab_stop(out, j);
    else
      out[j++] = c;
  }

  if (j > 0)
    out[j] = '\0';
}

int main(void) {
  char input[MAXLINE], output[MAXLINE];
  int linec;

  cinit(input, MAXLINE);
  cinit(output, MAXLINE);

  // lets assume 4 col tab stops: 0   4   8   12   16   20   24
  while ((linec = extract(input, MAXLINE)) > 0) {
    adjust(output, input);
    printf("\n%s", output);
  }

  return 0;
}
