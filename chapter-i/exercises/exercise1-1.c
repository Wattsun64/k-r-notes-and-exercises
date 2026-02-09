#include <stdio.h>

/*
 * Exercise 1-1. Run the "hello, world" program on you system. Experiment
 * with leaving out parts of the program, to see what error messages you get.
 */

int main(void) {
  printf("hello world\n");

  // Print empty string
  printf("");

  // Error: Missing terminating character
  printf("hello
  ");

  // Error: Too few arguments to function call, at least one expected
  printf();

}
