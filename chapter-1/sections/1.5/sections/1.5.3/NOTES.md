## 1.5.3 Line Counting

Here is a sample program for counting input lines:
```
#include <stdio.h>

int main(void) {
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;
  printf("%d\n", nl);

}
```

As mentioned in previous sections, the standard library ensures that an input text stream appears as a *sequence of lines*, each terminated by a newline (`\n`).

The double equals sign `==` is the C notation for *is equal to*.

A character written between single quotes (`'`) *represents an integer value* equal to the numerical value of the character within the machine's character set. This is called a *character constant*, which is another way of writing a small integer.

An example is the `'A'` character constant, which in the **ASCII** character set, has a value of `65`, the internal representation of the character **A**.

Another character constant example are the *escape sequences* used in string constants are also legal character constants. Meaning `'\n'` stands for the value of the *newline character*, and has a value of `10` in ASCII.
