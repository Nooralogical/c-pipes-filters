# c-pipes-filters

## About

This repository contains 5 short filterin program and one that calculates the characters, rows, whitespaces and words.

**all.c** removes all whitespaces

**cons.c** removes consecutive whitespaces by replacing them with one whitespace.

**empty.c** removes all empty lines

**block.c** removes all block comments like /*this*/

**line.c** removes all one line comments like //this

Using all of these piped together you can calculate just the written code in one source file without whitespaces, empty lines or comments.

## Usage

All programs can be run from the command line and piped to create filtered files or output straight to console.

Compile into a runnable program:

```
gcc calc.c -o calc
```

For example to calculate the source codes characters, whitespace, rows and words:

```
cat calc.c | ./calc
```

this will give you the console output:

```
Chars: 765
Whitespace: 523
Lines: 53
Words: 162
```

To use multiple filters, pipe them together. To remove all whitespace from a source file and calculate to see the result:

```
cat calc.c | ./all | ./calc
```

This gives you the output where the result can be seen:

```
Chars: 765
Whitespace: 0 
Lines: 53
Words: 48
```

Combine filters together to achieve the wanted result. If a separate file with the output is needed, in stead of console output:

```
cat calc.c | ./all | ./calc > file.text
```

##Thank you for reading!