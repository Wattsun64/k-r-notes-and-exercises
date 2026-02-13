## 1.5 Character Input & Output

Text input or output, regardless of where it originates or where it is going, is dealt with as *streams of characters*.

A *text stream* is a sequence of characters divided into lines; each line consists of zero or more characters followed by a *newline character* (`\n`).

The standard library (`<stdio.h>`) provides several functions for reading and writing one character at a time. The simplest of these functions are `getchar` and `putchar`.

Each time `getchar` is called, the function reads the *next input character* from a text stream, and returns that character as its value. An example of this:
```
c = getchar();
```

The variable `c` contains the next character of input;

The function `putchar` *prints* a character each time it is called:
```
putchar(c)
```

The above example prints the contents of the *integer* variable `c` as a character, usually to a display of sorts.
