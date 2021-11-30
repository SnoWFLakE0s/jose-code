# jose-code
A simple extension of the C language for doing basic tasks. Funny function names and operators based on quotes from our MA111 professor. Completely impractical.

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
