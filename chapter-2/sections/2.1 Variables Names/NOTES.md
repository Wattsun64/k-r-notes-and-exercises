## 2.1 Variable Names

There are some restrictions on the naming of variables, and symbolic constants. Variable/Symbolic Constant names are made up of *letters and digits* (the first character ***must*** be a letter).

The underscore (`_`) constitutes as a letter, and is sometimes useful for improving the readability of long variable names.

Upper and lower case letters are distinct, meaning `x` and `X` would be two different names for either a variable or constant. Traditional C practices are to use lowercase for variable names, and all uppercase for symbolic constants.

Note that the first 31 characters of an internal variable name are significant. For function names, and external variables, the number *may* be less than 31, because external variable/function names may be used by assemblers and loaders over which the language has no control.

For external names, the standard guarantees of uniqueness only for ***6*** characters in a single case.

Keywords `if`, `else`, `int`, `float`, etc. are reserved, and cannot be used for variable/function names.

It is wise to choose variable names that are related to the purpose of the variable/function, and that are unlikely to get mixed up elsewhere within the program.

Ideally, short names are used for local variables, especially within loops, and longer names for external variables.
