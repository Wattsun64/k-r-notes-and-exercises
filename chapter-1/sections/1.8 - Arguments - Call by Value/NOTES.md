## 1.8 Arguments - Call By Value

In C, all function arguments are passed *by value*. This means that the called function is given the values of its arguments in temporary variables rather than the originals.

For example:
```c
  #include <stdio.h>

  int power (int base, int n) {
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
      p = base * p;
  }

  int main(void) {
    int i;
    for (i = 0; i < 10; ++i)
      printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
  }
```

The line in which `printf` is called, in conjunction with two `power` calls:
```c
  printf("%d %d %d\n", i, power(2, i), power(-3, i));
```

When `i` is passed to both `power` calls, the value of `i` is the passed argument, **not** the original `i` variable:
```c
  /* assume i = 3 */
  printf("%d %d %d\n", i, power(2, 3), power(-3, 3));
```

Which means, any manipulation made within `power` to the passed `n` parameters, in this case `i`, will not effect the `i` variable within `main`. The manipulation only happens locally within `power`, due to the function having its own local/temporary copy of the variable, having no affect on the original.

> Call by value is an asset, however, not a liability. It usually leads to more compact programs with fewer extraneous variables, because parameters can be treated as conveniently initialized local variables in the called routine.

Here is an example of the above explanations, using an updated version of the `power` function:
```c
  #include<stdio.h>

  /* power: raise base to n-th power; n>=0; version 2*/
  int power(int base, int n) {
    int p;
    for (p = 1; n > 0; --n)
      p = p * base;
    return p;
  }
```

The parameter `n` is used as a *temporary variable*, and is counted down (a `for` loop that runs backwards) until it becomes zero; there is no longer a need for the variable `i`. Whatever is done to `n` ***inside*** `power` has no effect on the argument that `power` was originally called with (i.e. as per the explanation above).

When necessary, it is possible to arrange for a function to modify a variable in a calling routine (called function). This requires the caller to provide the *address* of the variable to be set (technically a *pointer* to the variable), and the called function <ins>***must***</ins> declare the parameter to be a *pointer* and access the variable indirectly through it.

The above statement is different for `arrays`. When the name of an array is used as an argument, the value passed to the function ***is*** the location/address of the beginning of the array - there is no copying of array elements.

By subscripting this value (accessing individual elements of an array) the function can access and alter any element of the array.
