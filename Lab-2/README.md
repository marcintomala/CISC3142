## Lab 2 - Objective

Objective: Create a calculator program using object-oriented techniques for data abstraction.

## Run Instructions

Assuming `g++` and `make` are present on our machine, all that is required to run the included code is to execute the command `make lab2` 
from the root directory of the repository. The `Makefile` is designed such that it will cd into and compile the code inside the `Lab-2` directory,
then run the program from there.

## Problem Statement

###Requirements
• A user-defined calculator struct type with an Operator enum within the same scope.
  o Create members, functions, constructors as needed for your program design.
• End-user input into program can be either mathematical expressions or text file input – clearly state your design/spec in your documentation
  o Allow different number types as operands, not just limited to int
  o Operators to include in your implementation (at minimum): add, subtract, multiply, divide, squareroot

## Solution

I decided to simplify the object-oriented aspect of the calculator by defining a `struct` which is created with one single member - the expression the user wants evaluated.
`Enum` is used to streamline the `switch` statements.

The program prompts the user for an expression to evaluate with minimal constraints - the onus on removing undesired characters falls on the program.
The only constraints of the program are:
  - The expression should not be empty
  - The expression should not contain two operators in a row "e.g. 5+5"
  - The notation for roots should be fractional powers (e.g. sqrt(2) -> 2^(1/2)).

The program parses the string in `infix_solver()` and evaluates using two stacks - one for operators and one for operands. Parentheses and order of operations is preserved.

## References

The solution was made with the help of (but not copied from) [this article](https://www.geeksforgeeks.org/expression-evaluation/). 

## Expected Output:

The program will output to the console the expression it parsed (if non-mathematical characters, such as letters, were introduced, they will be stripped),
as well as the result of the operations. 

Tests of the evaluation function:

Random test cases similar to the ones from class:
```
Inputs:
"1 + 1",
"(6+4)*(10-7)",
"6+4*10-7",
"6+(4*10)-7",
"asgasd15-431",
"2^(1/2)",
"2^5" 
```
Result:
```
Expression evaluated: 1+1
Result: 2
Expression evaluated: (6+4)*(10-7)
Result: 30
Expression evaluated: 6+4*10-7
Result: 39
Expression evaluated: 6+(4*10)-7
Result: 39
Expression evaluated: 15-431
Result: -416
Expression evaluated: 2^(1/2)
Result: 1.41421
Expression evaluated: 2^5
Result: 32
```
First 15 numbers of the Fibonacci sequence using the closed formula:
```
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^0-((1-(5^(1/2)))/2)^0)
Result: 0
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^1-((1-(5^(1/2)))/2)^1)
Result: 1
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^2-((1-(5^(1/2)))/2)^2)
Result: 1
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^3-((1-(5^(1/2)))/2)^3)
Result: 2
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^4-((1-(5^(1/2)))/2)^4)
Result: 3
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^5-((1-(5^(1/2)))/2)^5)
Result: 5
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^6-((1-(5^(1/2)))/2)^6)
Result: 8
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^7-((1-(5^(1/2)))/2)^7)
Result: 13
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^8-((1-(5^(1/2)))/2)^8)
Result: 21
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^9-((1-(5^(1/2)))/2)^9)
Result: 34
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^10-((1-(5^(1/2)))/2)^10)
Result: 55
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^11-((1-(5^(1/2)))/2)^11)
Result: 89
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^12-((1-(5^(1/2)))/2)^12)
Result: 144
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^13-((1-(5^(1/2)))/2)^13)
Result: 233
Expression evaluated: (1/5^(1/2))*(((1+(5^(1/2)))/2)^14-((1-(5^(1/2)))/2)^14)
Result: 377
```
