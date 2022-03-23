#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

//enum definition to streamline operator parsing and usage
enum operations {PLUS = '+', MINUS = '-', MULT = '*', DIV = '/', POW = '^'};

struct Calculator {
    //calculator struct; instantates a calculator with a given expression passed in the constructor
    //allows to evaluate the expression with infix_solver()
    string expression;
    Calculator (string expression);
    double evaluate (double x, double y, char op);
    double infix_solver();
};

//helper functions
bool is_math(char c);
int order(char op);