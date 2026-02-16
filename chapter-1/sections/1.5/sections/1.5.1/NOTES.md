## 1.5.1 File Copying

The simplest program for copying an input to its output one character at a time:
```c
  #include <stdio.h>

  /* copy input to output; 1st version */
  int main(void) {
    int c;
    c = getchar();
    while (c != EOF) {
      putchar(c);
      c = getchar();
    }
  }
```

The type `char` is specifically meant for storing character data, but an `int` type can be used as well.

In the example above, `int` is used when declaring `c`. The reason for doing so is subtle, but important, as the problem relates to distinguishing the end of the input from valid data.

The solution presented above as `(c != EOF)` is that `getchar` returns a *distinctive* value when there is no more input. A value that cannot be confused with any real character, this value is called `EOF`, or ***end of file***.

The declaration of `c` being an `int` is that the type must be big enough (`char` = 1 byte, `int` = 2 bytes) to store **ANY** value that `getchar` returns.

`EOF` is an *integer* defined within the `<stdio.h>` library, but the specific numeric value doesn't matter as long as it is not the same as *any* `char` value. By using the symbolic constant, this assures developers that nothing in the program depends on the specific numeric value.

For the sake of sticking to the general rules defined in the earlier sections, the program could be written as such:
```c
  #include <stdio.h>

  int main(void) {
    int c;
    while ((c = getchar()) != EOF)
      putchar(c);
  }
```

This version centralizes the input, now represented as the expression `(c = getchar())` appears as part of a larger expression, thus shrinking the program, making it easier to read.

The parentheses around the `(c = getchar())` assignment within the `while` condition (i.e. `while ((c = getchar()) != EOF)`) are necessary. The *precedence* of `!=` is *HIGHER* than `=`. Meaning in the absence of the parentheses, the relational test `!=` would be done *before* the assignment `=`. This makes the statement:
```c
  c = getchar() != EOF
```

Equivalent to:
```c
  c = (getchar() != EOF);
```

The result of the above would set `c` to `0` or `1`, depending on whether or not the call of `getchar` encountered `EOF`.
