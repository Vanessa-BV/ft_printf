# ft_printf

## Introduction
The task involves recreating the functionality of the printf() function from the C standard library. This exercise offers an opportunity to enhance programming skills, particularly in working with variadic functions in C.

## Project Overview
The goal is to implement an own version of the printf() function, named ft_printf(). The function prototype is:

c
Copy code
int ft_printf(const char *, ...);

## Requirements
To successfully complete this project,the following requirements need to be fulfilled:

Handle Conversions: The ft_printf() function should handle the following conversions: c, s, p, d, i, u, x, X, and %.
Buffer Management: It is not required to implement the buffer management system present in the original printf().
Comparison: The implementation will be compared against the original printf() to ensure correctness and compatibility.

## Supported Conversions
The ft_printf() function should support the following conversion specifiers:

* %c: Prints a single character.
* %s: Prints a string as defined by the common C convention.
* %p: Prints the hexadecimal representation of a void * pointer.
* %d/%i: Prints a decimal (base 10) number.
* %u: Prints an unsigned decimal (base 10) number.
* %x: Prints a number in hexadecimal (base 16) lowercase format.
* %X: Prints a number in hexadecimal (base 16) uppercase format.
* %%: Prints a percent sign.
