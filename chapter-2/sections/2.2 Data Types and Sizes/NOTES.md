## 2.2 Data Types & Sizes

There are only a few basic types within the C language:
```
  char   -- a single byte, capable of holding a single character in the local character set.
  int    -- an integer, typically reflecting the 'natural' size of integers on the host machine.
  float  -- single-precision floating point (ex. 1.3).
  double -- double-precision floating point (ex. 1.33).
```

There are a number of *qualifiers* (keywords that provide instructions to the compiler about how a variable should be treated/used) that can be applied to these basic types. `short` and `long` apply to integers:
```
  short int sh;
  long int counter;
```

The word `int` can be omitted in such declaration, and typically is.

The intent with `short` and `long` is to provide different ***lengths*** of integers, where practical. `int` is the typical natural size for a machine. `short` is often 16 bits, and `long` 32 bits, and `int` either 16 or 32 bits.

Each compiler has the ability to choose appropriate sizes for its own hardware, subject only to the restriction that `short` and `int` are *at least* 16 bits, where `long` is normally 32 bits, and a `short` is no longer than an `int`, which is no longer than `long`.

The qualifiers `signed` and `unsigned` can be applied to `char` or any integer (i.e. `int`, `short`, `long`). `unsigned` numbers are *always* positive or zero (i.e. 0-255), and obey the laws of arithmetic modulo $2^n$, where `n` is the number of bits in the type.

An example of the above would be if `char` are 8 bits, `unsigned char` variables are between -128 and 127 (in a two's compliment machine). Whether plain `char` are `signed` or `unsigned` is machine-dependent, but *printable* characters are ***always*** positive.

The type `long double` specifies extended-precision floating point. As with integers, the sizes of floating-point objects are implementation-defined. `float`, `double`, and `long double` could represent one, two, or three distinct sizes.

The standard headers `<limits.h>` and `<float.h>` contain symbolic constants for all of these sizes, along with other properties of the machine and compiler.
