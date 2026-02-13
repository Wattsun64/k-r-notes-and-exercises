#include <stdio.h>

/*
 * Exercise 1-3. Modify the temperature conversion program to print a heading
 * above the table.
 */

int main(void) {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 500;
  step = 30;

  fahr = lower;
  printf("====== °F/°C =====\n");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32);
    printf("%3.0f°F\t%6.1f°C\n", fahr, celsius);
    fahr = fahr + step;
  }
  printf("====== END ======\n");
}
