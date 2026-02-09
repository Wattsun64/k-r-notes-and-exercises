#include <stdio.h>

/*
 * Exercise 1-4. Write a program to print the corresponding Celsius
 * to Fahrenheit table.
 */

int main(void) {
  float celsius, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 500;
  step = 20;

  celsius = lower;
  printf("======== °C/°F =======\n");
  while (celsius <= upper) {
    fahr = (celsius * (9.0/5.0)) + 32;
    printf("%6.0f°C\t%3.0f°F\n", celsius, fahr);
    celsius = celsius + step;
  }
  printf("======== END ========\n");
}
