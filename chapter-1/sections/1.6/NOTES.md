## Arrays

Here is an example program that counts the number of occurrences of each digit, white space characters, and all other characters:
```c
  #include <stdio.h>

  /* count digits, white space, others */

  int main(void) {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (int i = 0; i < 10; i++)
      ndigit[i] = 0;

    while ((c = getchar()) != EOF)
      if (c >= '0' && c <= '9')
        ++ndigit[c - '0'];
      else if (c == ' ' || c == '\n' || c == '\t')
        ++nwhite;
      else
        ++nother;

    printf("digits =");
    for (int i = 0; i < 10; ++i)
      printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);

  }
```

While this program might seem arbitrary for it's use, it does however highlight various aspects of C within this single program.

The output of the above program (ran against itself) is:
```
  digits = 9 3 0 0 0 0 0 0 0 1, white space = 123, other = 345
```

The declaration:
```c
  int ndigit[10]
```

Declares `ndigit` to an array of `10` integers. Array subscripts (elements) always start at zero (aka *Zero Index*). Which means the elements are `ndigit[0], ndigit[1], ..., ndigit[9]`.

For the declared `ndigit` array, any subscript (element) can be any integer expression, which includes integer variables (such as `i`), and integer constants.

The sample program relies on the properties of the character representation of the digits. An example of this is the conditional test:
```c
  if (c >= '0' && c <= '9')
```

Determines whether the character value of `c` is a digit. If so, the numeric value of the digit is:
```c
  c - '0'
```

The above only works if `'0'`, `'1'`, ..., `'9'` have *consecutive* increasing values, which they do. As this is the case for ***ALL*** character sets.

By definition, `char` types are *small integers*, which makes any `char` variable and/or constants identical to an `int` within arithmetic expressions. Which is rather convenient, as `c - '0'` is an integer expression with a value between `0` and `9`, that also corresponds to the character `'0'` to `'9'` stored in C, making the value a valid subscript (element index) for the `ndigit` array.


