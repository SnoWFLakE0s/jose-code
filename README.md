# Josecode 
by First Joshua Eah and Matviy Zhachek 
for CS 102 Section C Fall 2021

# jose-code
A simple extension of the C language for doing basic tasks. Funny function names and operators based on quotes from our MA111 professor. Completely impractical.

# Language Structure
Files are saved to `.josecode` files. Code should be individual line-by-line statements, and the compiler will go through one line at a time.
The only data type in this language are floating-point numbers. This simplifies calculations a little.

# Features
* Functions:
  *  Logarithm: `loggers(x,a)`
     *  Logarithm of `x` with base `a`.
  *  Exponential: `power(x,a)`
     *  `a` to the power of `x`.
  *  Round: `dontCareAboutValue()`
     *  Rounds the input number to the nearest value.
  *  Maxiumum: `bigger(a,b)`
     *  Returns the larger number, `a` or `b`.
  *  Minimum: `smaller(a,b)`
     *  Returns the smaller number, `a` or `b`.
  *  Random: `jazzup(a,b)`
     *  Returns a random number between `a` and `b`.
* Math Operators:
  *  Addition Operator: `a PLUS b`
     *  Returns `a` plus `b`.
  *  Subtraction Operator: `a MINUS b`
     *  Returns `a` minus `b`.
  *  Multiplication Operator: `a TIMES b`
     *  Returns `a` times `b`.
  *  Division Operator: `\frac{a}{b}`
     *  Reuturns `a` divided by `b`.
* Logical Operators:
  * `EQUALTO`: Checks if two numbers are equal. Syntax: `a EQUALTO b`.
  * `NOT`: Checks if both numbers are not equal. Syntax: `a NOT b`
  * `OR`: Checks if either of two numbers are larger than 0. Syntax: `a OR b`.
  * `AND`: Checks if any of two numbers are larger than 0. Syntax: `a AND b`.
* Some Reserved Words:
  * `IFF{}{}`: If statements. If statement in first bracket is true, then execute the statement in 2nd bracket. 
  * `IS`: Variable assignment. Syntax: `a IS 5`
  * `RK:` Comments. The compiler will ignore this line for execution.

## Technical Description

Describe your project's source code in terms of algorithms and data structures.

## Screen Shots of Working Program

Add images here like this:
![Example image](./images/example.png)

## Link to YouTube video recording of presentation and code walk through.


