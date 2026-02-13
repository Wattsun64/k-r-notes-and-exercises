#include <stdio.h>

/*
 * Exercise 1-11.
 * How would you test the word count program?
 *
 * I would test the program with a variety of text inputs. Especially inputs with
 * a wide range of escape sequences, as we are only checking for blanks, newlines, and tabs.
 * Ideally we would want to have checks for other escape sequences backslashes, quotes (single/double),
 * backspace?, Null characters, etc.
 *
 * I would also use text inputs with other text standards (UTF-8, UTF-16, UTF-32, etc.). Right now we're
 * only accounting for ASCII.
 *
 *
 * What kinds of input are most likely to uncover bugs, if there are any?
 *
 * I believe the above mentioned tests would uncover various bugs, as this program is simple in it's checks
 * (only checking against blanks, newlines, and tabs), as well as (I'm assuming) testing againts words of the
 * english language. I would imagine other escape sequence characters would reveal bugs for this program.
 *
 * I assume the program in it's current state would have issues dealing with text input of other
 * languages.
 *
 * As mentioned above, text inputs using other text standards (UTF-8, etc.), and other character sets (that of other
 * langugages), would present bugs.
 *
 */

#define IN  1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main(void) {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}
