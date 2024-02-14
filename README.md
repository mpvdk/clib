# C standard library

This repo contains custom implementations of the c standard library.

I'm making it as a personal exercise to test and expand my knowledge of C. It is not meant to replace production implementations like glibc, which will most certainly be faster and more reliable.

# Using
Just copy the source and header files you want to use to your project and include them like you would any other custom translation unit. 

For example:
```
cp src/my_string.* /path/to/your/project
```
And in your project, use:
```
#import "my_string.h"
```
And then obviously add the source file to your dependencies when you build and the resulting object file when you assemble. 

# Testing
All modules and all functions are tested using the [unity unit testing framework](https://www.throwtheswitch.org/unity). 

All the test files are in the `tests` directory. Every module has it's own sub-directory. For example, `tests/string`. And every function has it's own test source and header file. For example, `tests/string/my_strcpy.c` and `tests/string/my_strcpy.h`.

The root Makefile has a target to build all tests, but also targets to test individual modules. 

So you can run
```
make all
```
But also, for example, 
```
make string
```
The executable that is built can then be found in `bld/bin`. 

# Status

Below you'll find a list of all the components of the C standard library and their status within this project.

Some of these are not very interesting and me be moved from the to-do list to the "won't do" list later if they're not very educational.

### Done:
- string

### Work in progress:
- stdio

### To-do:
- assert
- complex
- ctype
- errno
- fenv
- float
- inttypes
- iso646
- limits
- locale
- math
- setjmp
- signal
- stdalign
- stdarg
- stdatomic
- stdbool
- stddef
- stdint
- stdlib
- stdnoreturn
- tgmath
- threads
- time
- uchar
- wchar
- wctype

### Won't do:

