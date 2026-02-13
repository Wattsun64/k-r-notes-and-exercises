## 1.3 The For Statement

The `while` loop is a fantastic option for iterative loops. Another good option is the `for` loop. Here is the **Fahrenheit-Celsius** program written using the `for` loop:
```
#include <stdio.h>

int main(void) {
  int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
      printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}
```

The output of the program is the same as the one written with a `while` loop, but looks *quite* different.

The biggest difference is the removal of the majority of the previously declared variables (i.e. `celsius`, `lower`, `upper`, and `step`). Also notice that `fahr` is once again an `int` and not a `float`, with `lower`, `upper`, and the `step` being converted to *constants* within the `for` statement. The temperature conversion formula has been moved as the third argument to `printf`, as opposed to previously being a separate assignment statement.

The change of making the conversion formula can be thought of as a general rule:
> In any context where it is permissible to use the value of a variable of some type, you can use a more complicated expression of that type

An example of the above quote is the use of the conversion formula as the third argument to `printf`, as within the formatted string the `float` declaration `%6.1f` expects there to be `float` number, the expression `((5.0/9.0)*(fahr-32))` satisfies the expectation, and follows the *general rule*.

Think of this rule as a way of forgoing excessive amounts of typing, and writing statements/declarations when necessary. Using the example of the updated temperature conversion program, we pass the conversion formula as a way of *simplifying* the program, and passing the formula as an argument shows intention.

The choice between `while` and `for` are arbitrary, based on which seems clearer. The `for` loop is usually appropriate for loops in which initialization and increment are single statements, and logically related, as it is more compact than `while`. Thus keeping the loop control statement together in one place.
