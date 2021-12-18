# jose-code
A simple extension of the C language for doing basic tasks. Funny function names and operators based on quotes from our MA111 professor. Completely impractical. By Joshua Eah and Matviy Zhachek for CS-102 Section C Fall 2021.

# Language Structure
Files are saved to `.josecode` files. Code should be individual line-by-line statements, and the compiler will go through one line at a time.

# Features
## Functions
* `loggers ( a );`: takes the log of base `a`.
* `power (a, b);`: takes `a` to the power of `b`.
* `tellme ( );`: takes string, prints string. *tells you something.*
* `giveme ( );`: takes input from console. *gives the computer something*.
* `bigger ( a, b );`: returns the bigger of two numbers, `a` or `b`.
* `smaller ( a, b );`: returns the smaller of two numbers, `a` or `b`. 

___

# 1. Writing josecode
To begin writing josecode, simply create a plain text file with the file extension .josecode. Declare some variables like you would with any other C program:
```
int x;
```
You can now use them with other josecode functions, like in the program below, which returns the larger of the two numbers. Functions must be used inside the `tellme` function to get any output to the console. It is best practice to declare a `result` variable for your computation and for feeding into the `tellme` function. Proper function syntax is to put single spaces around the opening parentheses and a single space preceding the closing parenthese with a semicolon following it.
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

# 2. Compiler Usage Instructions
___
Using the josecode compiler is very simple. It is provided as a simple C program, inside the `/src` directory. Navigate to the `/src` directory within your shell, then build and run the program using the command `make run`.

The Makefile will automatically run the josecode compiler program, upon which you should be greeted with this message:
```
Welcome to the josecode compiler!
Please enter the name of your josecode program in the input directory, including the file extension:
```
If you now type your input josecode file, which you can easily test out by running any of the four example programs provided, the compiler will interpret and build the josecode program. For example, to run the `example_2.josecode` file, simply type `example_2.josecode` in response to the compiler's prompt:
```
>> example_2.josecode
```
Upon a successful building of the josecode program, a log will be printed:
```
LOG:
Intermediary file successfully created.
Beginning C conversion...
Finished josecode compilation! Me likey. 
Now running program...
```
Now your josecode program should run.
On instructions to actually *write* josecode, refer to section 1.

# 3. Technical Description

Simply put, our program produces a .c file based on some basic .josecode input. A lot of it is effectively a find-and-replace, but certain basics like the c file headers are automatically created which makes writing josecode marginally simpler to write than barebones C.

First, josecode opens your choice of an input file, then an intermediary output file. 

It then proceeds scan over the entire input file, character by character, looking for any blankspaces.
Once it finds a blankspace, it will replace or token it with a NULL character. It then writes each character to the intermediary output file.

Once the intermediary file is created, josecode reopens the file to be read instead of written to, and then opens an accompanying `output.c` file to be written to. The first strings that are written to the `output.c` file are the essential parts of a c file such as the header inclusions and the main function declaration.
Then the josecode compiler replaces any josecode functions with their C counterparts. 
Before doing that however, any text detected inside a parenthese is concatenated onto a single line due to string limitations in C.
Once the josecode is translated and inserted into the `output.c` file, `return 0` and a closing bracket are inputted to satisfy the c compiler.

Once the josecode compiling is over, a system command is run to make and run the `output.c` file.
Josecode is now executed.

## Some screenshots of running josecode:

![josecode input](https://github.com/SnoWFLakE0s/jose-code/blob/main/images/demonstration%20input.PNG?raw=true)
![josecode intermediary](https://github.com/SnoWFLakE0s/jose-code/blob/main/images/output%20txt.PNG?raw=true)
![josecode output](https://github.com/SnoWFLakE0s/jose-code/blob/main/images/output%20c.PNG?raw=true)
![josecode running](https://github.com/SnoWFLakE0s/jose-code/blob/main/images/make%20run.PNG?raw=true)

## A YouTube video walkthrough of josecode!
[Click me to view the walkthrough video with Josh and Matt!](https://youtu.be/jdNY1pUd42k)

