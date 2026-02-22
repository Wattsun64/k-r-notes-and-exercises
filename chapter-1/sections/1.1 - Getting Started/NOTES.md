## 1.1 Getting Started

Creating a C program, for this example within the UNIX system, the program must be created in a file with the `.c` extension (i.e. `hello.c`) and compiled using:
```sh
  cc hello.c
```

Note: the `gcc` compiler can be used as well:
```sh
  gcc hello.c
```

The `cc` command is a generic command name for the system's default C compiler, while `gcc` is the specific command for the **GNU C Compiler** that is part of the broader **GNU Compiler Collection (GCC)** suite.

To specify a different output file name with either `cc` or `gcc`, use the `-o` flag with the specified output name:

```sh
# Using file name as output
  cc hello.c -o hello
  gcc hello.c -o hello

# Can be named completely different
  cc hello.c -o main
  gcc hello.c -o h
```

The `main` function is responsible for executing the program. Everything C program *must* contain a `main` function.

```c
  #include <stdio.h>

  int main(void) {
    printf("hello, world\n");
    return;
  }
```

The first line of the above program calls for `#include <stdio.h>`. This tells the compiler to include information about the standard input/output library.

A sequence of characters in double quotes, such as `"hello, world\n"` is called a *character string* or a *string constant*.

An *escape sequence* such as `\n` provides developers a general and extensible for representing *hard-to-type* or invisible characters.
