# jose-code
A simple extension of the C language for doing basic tasks. Funny function names and operators based on quotes from our MA111 professor. Completely impractical. By Joshua Eah and Matviy Zhachek for CS-102 Section C Fall 2021.

# Language Structure
Files are saved to `.josecode` files. Code should be individual line-by-line statements, and the compiler will go through one line at a time.
The only data type in this language are floating-point numbers. This simplifies calculations a little.

# Features
* Functions:
  *  Logarithm: `loggers ( x,a )`
     *  Logarithm of `x` with base `a`.
  *  Exponential: `power ( x,a )`
     *  `a` to the power of `x`.
  *  Round: `dontCareAboutValue()`
     *  Rounds the input number to the nearest value.
  *  Maxiumum: `bigger ( a,b )`
     *  Returns the larger number, `a` or `b`.
  *  Minimum: `smaller ( a,b )`
     *  Returns the smaller number, `a` or `b`.
  *  Random: `jazzup ( a,b )`
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

___

# Writing josecode
To begin writing josecode, simply create a plain text file with the file extension .josecode. Declare some variables like you would with any other C program:
```
int x;
```
You can now use them with other josecode functions, like in the program below, which returns the larger of the two numbers. Functions must be used inside the `tellme` function to get any output to the console. It is best practice to declare a `result` variable for your computation and for feeding into the `tellme` function. Proper function syntax is to put single spaces around the parentheses.
```
int x = 1;
int y = 2;
int result = bigger ( x,y );
tellme ( "The larger of x and y is %d\n", result );
```
Try running the example program above. To run a josecode program, make and run the josecode compiler. Running the compiler will prompt you for the josecode file. By this point, you should have placed your .josecode file inside `/input/`. Now, just type `name_of_file.josecode` when asked for the file, and the josecode compiler will build and run your new program. Congrats! You've just ran a josecode program.

Result:
```
>> The larger of x and y is 2
```
Here's the more advanced version of this program, which prompts for user input via the `giveme` function. 
```
int x;
int y;
tellme ( "Input your first number: " );
giveme ( "&d", &x );
tellme ( "Input your second number: " );
giveme ( "&d", &y );
int result = bigger ( x,y );
tellme ( "The larger of x and y is %d\n", result );
```
Welcome to josecode!
___

## Technical Description

Simply put, our program produces a .c file based on some basic .josecode input. A lot of it is effectively a find-and-replace, but certain basics like the c file headers are automatically created which makes writing josecode marginally simpler to write than barebones C.

First, the input file is opened and ran over by a string function to replace josecode function keywords with their equivalent in C.

Then an intermediary output file (.c) is created, which is then ran through GCC in order actually run the josecode program.

## Screen Shots of Working Program

Add images here like this:

![alt_text](imagedirectory)

## Link to YouTube video recording of presentation and code walk through.


