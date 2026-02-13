## 1.5.4 Word Counting

Throughout the previous sections, there have been programs for counting lines, words, and characters, all of which useful. With words, the loose definition being that a word is *any sequence of characters that does not contain a blank, tab, or newline*.

Here is a bare-bones version of the UNIX program `wc`:
```
#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

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
```

The use of *symbolic constants* is preferred, even in smaller programs such as with `IN` and `OUT` in the example above, in order to make the program readable.

> Developers find it easier to make extensive changes in programs where magic numbers appear only as symbolic constants.
