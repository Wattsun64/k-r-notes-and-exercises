## 1.7 Functions

A `function` is equivalent to a subroutine, a series of commands to execute in the given order. This provides a convenient way to group computation, allowing developers to utilize a function within the program, without having to worry about its implementation (the process in which it works).

> With properly designed functions, it is possible to ignore *how* a job is done; knowing *what* is done is sufficient.

To illustrate creating, and executing a function, take for example that C does not provide any exponentiation operator such as `**` provided by other languages to achieve exponential computation. A potential solution could be creating a `power(m, n)` to raise an integer (`m`) to a positive integer power (`n`):
```
  #include <stdio.h>

  int power(int m, int n);

  /* test power function */
  int main(void) {

    int i;
    for (i = 0; i < 10; ++i)
      printf("%d %d %d\n", i, power(2,i), power(-3,i));
    return 0;
  }

  /* power: raise base to n-th power; n >= 0 */
  int power(int base, int n) {
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
      p = p * base;
    return p;
  }
```

A function definition has this form:
```
  return-type function-name(parameter declarations, if any) {
    declarations
    statements
  }
```

Function definitions can appear in any order, and in one source file or several, although no function can be split between files.

The first line of `power` itself:
```
  int power(int base, int n)
```

This declares the parameter types and names, and the type of the result that the function returns. The names used by `power` for its parameters are local to `power`, and are not visible to any other function: other routines can use the same names without conflict, which is also true of variables `i` and `p`: the `i` in `power` is unrelated to `i` in `main`.

The value that `power` computes is returned to `main` by the `return` statement. ***ANY*** expression may follow `return`:
```
  return <expression>;
```

A function does not always need to return a value; a `return` statement with no expression causes control, but no useful value, to be returned to the caller, as does *\"falling off the end\"* of a function by reaching the terminating right brace (`}`).

Take notice that in the `main` program, there is a `return` statement at the end. Since `main` is a function like any other, it may return a value to its caller (the system).

Typically, a return value of `0` implies *normal termination*; ***non-zero*** values signal unusual or erroneous termination conditions.

The declaration:
```
  int power(int m, int n);
```

Just before `main` says that `power` is a function that expects two `int` arguments,and returns an `int`. This declaration, which is called a *function prototype*, has to agree with the definition and uses of `power`. An error will occur if the definition of a function or *any* uses of it do **not** agree with its prototype (should one be declared).

Take note that *function prototype* parameter names do not need to mirror the full function declaration. Also, for *function prototypes*, parameter names are *optional*. Meaning the *function prototype* for `power` could have been written as:
```
  int power(int, int);
```

However, well-chosen parameter names are good documentation, and is best practice to include/use them.
