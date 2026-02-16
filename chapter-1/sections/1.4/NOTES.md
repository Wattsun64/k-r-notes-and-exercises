## 1.4 Symbolic Constants

Another good general rule to follow is:
> It is bad practice to bury "magic number"

Using the temperature conversion program, the numbers 300 and 20 convey little information to someone who might have to read the program later on in the future, making them hard to change in a systematic way.

One way to deal with *magic numbers* is to give them meaningful names. Using the `#define` line allows developers to define a *symbolic name* or *symbolic constant* to be a particular string of characters:
```
  #define name <replacement text>
```

This allows for developers to see any occurrence of `name` (not in quotes and not part of another name) and know that it will be replaced by the corresponding *replacement text*.

Note: the *replacement text* can be any sequence of characters, and is not limited to only numbers.

Updating the conversion with constants could look like:
```c
  #include <stdio.h>

  #define LOWER 0
  #define UPPER 300
  #define STEP 20

  int main(void) {
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
      printf("%3d°F %6.1f°C\n", fahr, ((5.0/9.0) * (fahr-32)));
  }
```

The values of `LOWER`, `UPPER`, and `STEP` are now symbolic constants, and not variables, as they do not appear in declarations.

Symbolic constant names are conventionally written in upper case as to make them readily distinguished from lower case variable names.

Note: there is no semicolon `;` at the end of the `#define` line.
