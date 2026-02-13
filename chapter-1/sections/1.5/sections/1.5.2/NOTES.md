## 1.5.2 Character Counting

Here is an example of a program that *counts* characters, somewhat similar to the copy program:
```
#include <stdio.h>

/* count characters in input; 1st version */
int main(void) {
  long nc;

  nc = 0;
  while (getchar() != EOF) {
    ++nc;
    printf("%ld\n", nc);
  }
}
```

The statement `++nc` uses the `++` operator, which means to *increment by 1*.

It is possible to write `nc = nc + 1`. However, it is more *concise* and often more efficient to use `++nc`.

The corresponding `--` operator is used to *decrement by 1*.

The operators `++` and `--` can be either *prefixed* (`++nc`) or `postfix` (`nc++`).

In the counting program, the count is accumulated into a `long` variable (`nc`) as opposed to an `int`. This is because `long` integers are at least *32 bits*. Although it is worth noting that on some machines both `int` and `long` are the *same* size, but on most machine an `int` is *16 bits* with a maximum value of `32767`, and would take relatively little input to overflow an `int` counter.

The conversion specification `%ld` tells `printf` that the corresponding argument is a `long` integer.

Another example of the counting program can be written with a `for` loop:
```
#include <stdio.h>

/* count characters in input; 2nd version */
int main(void) {
  double nc;

  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f\n", nc);
}
```

Note that `printf` uses `%f` for both `float` and `double`. `%.0f` suppresses printing of the decimal point and the fraction part, which is zero.

In the above program the body of the `for` loop is *empty* (`;`), as the all of accumulation work is done within the test and increment parts of the `for` expression. However, the grammatical rules of C require that a `for` statement **have** a body. The isolated semicolon, called *null statement*, is there to satisfy the requirement.

Something to make note of regarding both `while` and `for` loops is that the test conditional happens at the *top* of the loop, before proceeding with the body. If there is nothing to do, nothing is done, even if it means never going through the loop body.

> Programs should act intelligently when given zero-length input. The `while` and `for` statements help to ensure that programs do reasonable things with boundary conditions
