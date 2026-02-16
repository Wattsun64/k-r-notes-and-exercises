#include <stdio.h>

/*
 * Exercise 1-15. Rewrite the temperature conversion program of Section 1.2
 * to use a function for conversion
 */

// Function prototype
float fahr_to_celsius(float temp);

int main(void) {
  float fahr;
  int lower, upper, step;

  lower = -300;
  upper = 300;
  step = 30;

  fahr = lower;
  while (fahr <= upper) {
    printf("%3.0f°F\t%6.1f°C\n", fahr, fahr_to_celsius(fahr));
    fahr = fahr + step;
  }
}

float fahr_to_celsius(float temp) {
  return (5.0/9.0) * (temp-32);
}
