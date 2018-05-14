<a id="markdown-coding-chart" name="coding-chart"></a>
# Coding Chart

- **You do not talk about the coding chart**
- **You do not talk about the coding chart**
- **Code in English**
- **Use Kernighan & Ritchie indentation style**

<!-- TOC insertAnchor:true -->

- [Coding Chart](#coding-chart)
    - [Names](#names)
        - [camelCase](#camelcase)
        - [Typedef & Struct](#typedef-struct)
        - [Function names](#function-names)
        - [Pointers](#pointers)
    - [Formatting](#formatting)
        - [Brace placement](#brace-placement)
        - [Developped structures](#developped-structures)
        - [Parentheses for ternary operation](#parentheses-for-ternary-operation)
        - [Parentheses at long return](#parentheses-at-long-return)
        - [Avoid long lines](#avoid-long-lines)
        - [One variable per line](#one-variable-per-line)
    - [Commenting](#commenting)
        - [Structure](#structure)
        - [Function](#function)

<!-- /TOC -->

<a id="markdown-names" name="names"></a>
## Names

<a id="markdown-camelcase" name="camelcase"></a>
### camelCase

Always use **camelCase** for fonctions and variables name.

```c
int myVariableName;
int myFunctionName(int integerArgument, float anotherArgument);
```

<a id="markdown-typedef--struct" name="typedef--struct"></a>
### Typedef & Struct

Name a type with a capital letter for the first one, and name the structure by the same name with an underscore at the end.

```c
typedef struct Point_ {
    float x;
    float y;
    float z;
} Point;
```

<a id="markdown-function-names" name="function-names"></a>
### Function names

Use prefixes or suffixes and make their name clear.

```c
void export(); // is bad
void exportObjectsToFile(); // is good
```

<a id="markdown-pointers" name="pointers"></a>
### Pointers

Put the pointer near the name of the variable.

```c
char *str;
```

<a id="markdown-formatting" name="formatting"></a>
## Formatting

<a id="markdown-brace-placement" name="brace-placement"></a>
### Brace placement

Brace opening at the end of the line, and closing at the line after the last OR on the same line for one-line statements.

```c
int add(int a, int b) {
    return a + b;
}

// Works too
int add(int a, int b) {return a + b;}
```

<a id="markdown-developped-structures" name="developped-structures"></a>
### Developped structures

Write the structure's content on multiple lines.

```c
struct foo {
    int a;
    int b;
};
```

<a id="markdown-parentheses-for-ternary-operation" name="parentheses-for-ternary-operation"></a>
### Parentheses for ternary operation

Make sure to put parentheses around a condition in a ternary operation.

```c
int a  = (b > c) ? 0 : 1;
// Remember, this is equivalent to: if(b > c) {int a = 0;} else {int a = 1;}
```

<a id="markdown-parentheses-at-long-return" name="parentheses-at-long-return"></a>
### Parentheses at long return

```c
return 1; // is okay
return 7 + 2 - sqrt(1/2); // is bad
return (7 + 2 - sqrt(1/2)); // is good
```

<a id="markdown-avoid-long-lines" name="avoid-long-lines"></a>
### Avoid long lines

Conventionally, lines in while coding should not exceed 78 characters, based on monitor size.

<a id="markdown-one-variable-per-line" name="one-variable-per-line"></a>
### One variable per line

```c
int a;
int b;
```

<a id="markdown-commenting" name="commenting"></a>
## Commenting

<a id="markdown-structure" name="structure"></a>
### Structure

Describe briefly what the structure is for or what it is.

```c
/* Vector: Contains a vector position */
typedef struct Vector_ {
    double x;
    double y;
    double z;
} Vector;
```

<a id="markdown-function" name="function"></a>
### Function

Functions must be documented following the phpdoc style (without describing the type of the variables).

- First, describe what the function does 
- Then, describe the inputs
- Finally, describe the output

```c
/**
* Export numbers into a file
*
* @param finelame: Name of the file to export
* @param data: Table of string to serialize
*
* @return void
*/
void exportToFile(char *filename, int *data) {
    ...
}
```
