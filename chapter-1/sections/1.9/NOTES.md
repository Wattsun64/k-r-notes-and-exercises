## 1.9 Character Arrays

The most used type of array in C is the *character array*.

Here is an outline of a typical (albeit simple) function/program:
```
  while (there's another line)
    if (line is longer than the previous longest)
      save it
      save its length
  print longest line
```

The outline above states rather clear that the program divides naturally into pieces. One piece retrieves the new line, the next piece test, the next saves, and the rest controls the process.

A simple command called `getline` that fetches the next line of input, could be very useful within the above process:
```c
  /* getline: read a line int s, return length */
  int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
      s[i] = c;

    if (c == '\n') {
      s[i] = c;
      ++i;
    }

    s[i] = '\0';
    return i;
  }
```

The next necessary function that is required in the above outline could be one called `copy`, to copy a new line of input to a safe place:
```c
  /* copy: copy 'from' into 'to'; assume 'to' is big enough */
  void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
      i++;
  }
```

To bring the outline to full fruition, here is a full program that executes the prescribed outline above:
```c
  #include <stdio.h>

  #define MAXLINE 1000

  int getline(char line[], int maxline);
  void copy(char to[], char from[]);

  int main(void) {
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
      if (len > max) {
        max = len;
        copy(longest, line);
      }

    if (max > 0)
      printf("%s", longest);

    return 0;
  }

  /* getline: read a line int s, return length */
  int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
      s[i] = c;

    if (c == '\n') {
      s[i] = c;
      ++i;
    }

    s[i] = '\0';
    return i;
  }

  /* copy: copy 'from' into 'to'; assume 'to' is big enough */
  void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
      i++;
  }
```

A few highlights regarding the full program:
- The purpose of supplying the size of an array in a declaration is to set aside storage
- The length of the array `s` is not necessary in `getline` since its size is set in `main`
- The return type of `copy` is `void` to indicate that it explicitly has no return value

`getline` puts the character `\0` (the ***null character***, whose value is zero) at the *end* of the array it is creating, to mark the end of the string of characters.

This convention is used by C. When a string constant, such as:
```
  "hello\n"
```

Appears in a C program, it is stored as an array of characters containing the characters of the string, and terminated with `\0` to mark the end.
```
| h | e | l | l | o | \n | \0 |
```

The `%s` format specification in `printf` ***expects*** the corresponding argument to be a string represented in this form.
