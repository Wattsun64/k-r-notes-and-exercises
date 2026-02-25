#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
 * Exercise 2-1. Write a program to determine the ranges of `char`, `short`, `int`, and `long`
 * variables, both `signed` and `unsigned`, by printing appropriate values from standard headers
 * and by direct computation.
 *
 * Harder if you compute them: determine the ranges of the various
 * floating-point types
 */


int main(void) {
  // char
  printf("char range: %d-%d\n", CHAR_MIN, CHAR_MAX);
  printf("unsigned char range: %d-%d\n", 0, UCHAR_MAX);
  printf("signed char range: %d-%d\n", SCHAR_MIN, SCHAR_MAX);

  // short
  printf("short (signed) range: %d-%d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short range: %d-%d\n", 0, USHRT_MAX);

  // int
  printf("int (signed) range: %d-%d\n", INT_MIN, INT_MAX);
  printf("unsigned int range: %d-%d\n", 0, UINT_MAX);

  // long
  printf("long (signed) range: %ld-%ld\n", LONG_MIN, LONG_MAX);
  printf("unsigned long range: %d-%ld\n", 0, ULONG_MAX);

  return 0;
}
