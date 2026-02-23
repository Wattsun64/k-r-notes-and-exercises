## External Variables and Scope

In previous programs written, particularly last section's, the variables in `main`, such as `line`, `longest`, etc., are *private* or *local* to `main`. This is because they are declared within `main`, and therefore, no other function(s) have direct access to them.

The same is true for other functions. An example of this would be `i` in the `getline` function used in previous sections, as well as `i` in `copy`. Both variables are unrelated.

Each local variable in a function comes into existence only when the function (i.e. `getline`, `copy`, etc.) is called, and disappears once the function is exited.

Note that automatic variables (***local variables***) come and go with function invocation, as such, they do not retain their values from one call to the next, and must be explicitly set upon *each* entry. If variables are ***not*** set, they will contain garbage:
```c
  int i;     // i = -9338784;
  int i = 0; // i = 0
```

As an alternative to automatic (***local variables***), it is possible to define variables that are *external* to all functions. That is to say, variables that can be accessed by name within ***any*** function:
```c
  #include <stdio.h>
  int i;

  void printi() {
    extern int i;          // declare use of external variable `i`
    printf("i = %d\n", i); // print current value of external variable `i`
  }

  int main(void) {
    extern int i; // declare use of external variable `i`

    i = 0;        // now external variable `i` = 0
    printi();     // 'i = 0'
    return 0;
  }
```

Because *external variables* are globally accessible, they can be used instead of argument lists to communicate date between functions. Another noteworthy feature of *external variables* is that because external variables remain in existence permanently, rather than appearing and disappearing as functions are called, and exited, they *retain* their values even after functions have set them (*external variables*) have returned/exited:
```c
  #include <stdio.h>
  int i;

  void printi() {
    extern int i;          // declare use of external variable `i`
    printf("i = %d\n", i); // print current value of external variable `i`
  }

  void seti(int n) {
    extern int i;
    i = n;
  }

  int main(void) {
    extern int i; // declare use of external variable `i`

    i = 0;        // now external variable `i` = 0
    printi();     // 'i = 0'
    seti(10);     // setting external variable `i` = 10
    printi();     // 'i = 10'

    return 0;
  }

```

An external variable must be *define*, exactly once, outside of ***any*** function, allowing for storage to be set aside. The variable must also be *declared* in each function that wants/needs access to it, also stating it's type. The declaration may be an explicit `extern` statement or may be *implicit* from context:
```c
  #include <stdio.h>

  int i;

  int main(void) {
    extern int i; // declare use of external variable `i`
    return 0;
  }
```

Here is an example of external variable usage, utilizing the previous **longest line** program:
```c
  #include <stdio.h>

  #define MAXLINE 1000

  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  int gline(void);
  void copy(void);

  /* print longest input line; specialized version */
  int main(void) {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = gline()) > 0)
      if (len > max) {
        max = len;
        copy();
      }

    if (max > 0)
      printf("%s", longest);

    return 0;
  }

  /* gline: specialized version */
  int gline(void) {
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1
      && (c = getchar()) != EOF && c != '\n'; ++i)
      line[i] = c;

    if (c == '\n')
      line[i++] = c;

    line[i] = '\0';
    return i;
  }

  /* copy: specialized version */
  void copy(void) {
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
      i++;
  }
```

The external variables in `main`, `getline`, and `copy` are defined by the first lines of the example code above, which state their type, and thus, allocating storage for them.

Syntactically, external variable definitions are the same as local definitions. The main difference being their declaration occurs outside of functions, making them external.

Before a function can *use* an external variable, the name of the variable must be made *known* to the function. One way of doing this is to write an `extern` declaration inside the function. The declaration of accessing external variables is the same as local declarations, except for the added `extern` keyword.

In some circumstances, the `extern` declaration can be omitted. If the definition of an external variable occurs in the source file before its use in a particular function, then there is no need to use an `extern` declaration. Making the `extern` declarations in `main`, `getline`, and `copy` redundant. It is common practice to place all *external variable* definitions at the beginning of the source file, and omit the `extern` declaration.

If the program is divided into several source files, and a variable is defined in *file1*, and used in *file2* and *file3*, then `extern` declarations are needed in both *file2* and *file3* in order to connect the occurrences of the variable.

The usual practice is to collect `extern` declarations of variables and functions in a separate file, historically called a ***header***, that is then included by `#include` at the beginning of each each source file.

The suffix `.h` is conventional for header file names.

The functions of the standard library, for example, are declared in the headers like `<stdio.h>`.

For clarification, with regards to providing definitions of the use of *definition* and *declaration*:
- ***Declaration*** - refers to the place where the nature of the variable is *stated*, but *no storage is allocated* (i.e. `int i;`).
- ***Definition*** - refers to the place where the variable is *created* or *assigned* storage (i.e. `i = 0;`).

It is easy to develop a tendency to make *everything* within a program an `extern` variable because of flexibility, and how it appears to simplify communications, shorten argument lists, etc. as the variables are *always* there when desired.

The above is also a reason as to why it is not a good idea to rely heavily on their usage. This could lead to writing programs with data connections that are not obvious, variables being changed in unexpected and even inadvertent ways, making programs hard to modify.

Note that the above program quite inferior to the first, for the reasons mentioned above, as utilizing external variables destroys the generality of the two useful functions `getline`, and `copy` by wiring into them the names of the variables they manipulate.
