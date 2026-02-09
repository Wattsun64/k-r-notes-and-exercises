## 1.1 Getting Started

Creating a C program, for this example within the UNIX system, the program must be created in a file with the `.c` extension (i.e. `hello.c`) and compiled using:
```
cc hello.c
```

Note: the `gcc` compiler can be used as well:
```
gcc -o hello hello.c
```

The `cc` command is a generic command name for the system's default C compiler, while `gcc` is the specific command for the **GNU C Compiler** that is part of the broader **GNU Compiler Collection (GCC)** suite.

To specify a different output file name with either `cc` or `gcc`, use the `-o` flag with the specified output name:

```
// Using file name as output
cc hello.c -o hello
gcc hello.c -o hello

// Can be named completely different
cc hello.c -o main
gcc hello.c -o h
```

The `main` function is responsible for executing the program. Everything C program *must* contain a `main` function.

```
#include <stdio.h>

int main(void) {
  print_f("hello, world\n");
  return;
}
```

The first line of the above program calls for `#include <stdio.h>`. This tells the compiler to include information about the standard input/output library.

A sequence of characters in double quotes, such as `"hello, world\n"` is called a *character string* or a *string constant*.

An *escape sequence* such as `\n` provides developers a general and extensible for representing *hard-to-type* or invisible characters.

## 1.2 Variables & Arithmetic Expressions

This sections program will use the formula `°C = (5/9)(°F-32)` to print a table of Fahrenheit temperatures and their centigrade or Celsius equivalents.

In the example program, the two lines:
```
/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
```

Represent a comment. Any characters between `/*` and `*/` are ignored by the compiler.

In C, all variables must be declared before they are used, usually at the beginning of the function before any executable statements. A *declaration* announces the properties of the variable.

The type `int` means that the variable declared is an *integer*. Variables with type `float` (i.e. numbers that may have a fractional part).

The range between `int` and `float` depends on the machine being used; 16-bit `ints` lie between `-32768` and `32767` are common, as are 32-bit `ints`.

A `float` number is typically of the 32-bit quantity, with at least six significant digits, and magnitude between 10^-38 and 10^38.

C provides several other basic data types besides `int` and `float`, including:
- `char`    - character - a single byte
- `short`   - short integer
- `long`    - long integer
- `double`  - double-precision floating point

The sizes of the above types are also machine-dependent. Other types provided by C are *arrays*, *structures*, and *unions*. All types can have dedicated *pointers*, and finally *functions* that can return them.

The `printf` function is a general-purpose output formatting function. Its first argument is a string of characters to be printed. Any `%` construction will be substituted (with the provided format) with the arguments provided:
```
printf("%d\t%d\n", fahr, celsius);
```

The corresponding arguments to `printf` *MUST* match the up properly by number position, and type. Otherwise the wrong information will be displayed.

List of `%` constructors:
- `%c` - displays `char`
- `%d` - displays `int`
- `%f` - displays `float`
- `%p` - displays `pointer`
- `%s` - displays `string`

The behavior of `printf` is defined in the **ANSI** standard.

Augmenting any `%` constructor with an integer will dictate the rendered items width:
```
printf("%3d\t%6d\n", farh, celsius);
```

Will print the first digit at a width of three digits wide, and the second digit as six digits wide.

Something to take note of with the arithmetic logic used for the temperature conversion:
```
celsius = 5 * (fahr-32) / 9;
```

Is that the conversion is done with *integer arithmetic*, which makes the Celsius temperatures not accurate. An example of this is `0°F` is actually about `-17.8°C` not `-17`.

In order to get a more accurate temperature reading the conversion should be made with *floating-point arithmetic*. The updated conversion formula will look like:
```
celsius = (5.0/9.0) * (fahr-32.0);
```

Which is similar to the prior conversion, with a few differences. The updated program looks like:
```
#include <stdio.h>

int main(void) {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 30;

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  return;
}
```

The conversion formula is written in a natural way, and more accurate. In the prior conversion, using `5/9` would have resulted in `0` as both `5` and `9` are considered `ints`, and not `floats`, thus resulting in a truncated answer of `0`.

A decimal point in a number constant indicates that the number is indeed a `float`, thus allowing `5.0/9.0` not to truncate because it is the ratio of two floating-point values (i.e. `0.56`).

If an arithmetic operator has integer operands, an *integer operation* is performed. However, if an arithmetic operator has one floating-point operand and one integer operand, the integer operand will be converted to floating point before the operation is done.

Writing floating-point constants with explicit decimal points, even when the decimal is zero, can indicate the numbers purpose for the sake or readability.

Even in the assignment:
```
fahr = lower
```

And the test:
```
while (fahr <= upper)
```

Convert the `int` to a `float` before either operation is complete.

  In the `printf` conversion specification of `%3.0f` indicates that the floating-point number (`fahr`) will be printed at least three characters wide, with **NO** decimal point, nor fraction digits. The specification of `%6.1f` dictates that the next number (`celsius`) will be printed at least six characters wide, and with 1 digit after the decimal point.

Width and precision can be omitted from a specification: `%6f` indicates that the number is to be at least six characters wide; `%.2f` specifies two characters after the decimal point, but the width is not constrained, and `%f` merely says to print the number as a floating-point.

```
  %d      print as decimal integer
  %6d     print as decimal integer, at least 6 characters wide
  %f      print as floating point
  %6f     print as floating point, at least 6 characters wide
  %.2f    print as floating point, 2 characters after decimal point
  %6.2f   print as floating point, at least 6 characters wide and 2 after decimal point
```

Among other specifications, `printf` recognizes `%o` for `octal`, `%x` for `hexadecimal`, `%c` for `character`, `%s` for `character string`, and `%%` for `%` itself.
