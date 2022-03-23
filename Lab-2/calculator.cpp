#include "calculator.h"

Calculator::Calculator(string expression) {
    //constructor, takes a string and assigns the member expression to the input string
    this->expression = expression;
}

double Calculator::evaluate (double x, double y, char op) {
    //computing function. given two doubles and operator produces result
    switch(op) {
        case PLUS:
            return x + y;
        case MINUS:
            return x - y;
        case MULT:
            return x * y;
        case DIV:
            return x / y;
        case POW:
            //since we're dealing with doubles, the pow function covers exponents as well as roots:
            return pow(x, y);
        default:
            return 0;
    };
}

double Calculator::infix_solver() {
    string expression = this->expression;
    //without converting infix to postfix, we evaluate the infix expression directly
    //first, we remove invalid characters:
    expression.erase(remove_if(expression.begin(), expression.end(), is_math), expression.end());
    if (expression == "") {
    //if following this operation the string is empty, we throw an error
        throw runtime_error("The expression could not be meaningfully evaluated. Please try again.");
    }
    //we need to parse multi digit numbers correctly - for that we'll use a string which we'll later parse to double:
    string current = "";
    //two stacks to hold the values and operators:
    stack<double> operands;
    stack<char> operators;
    //notifying the user what was actually evaluated (in case the input contained values discarded earlier)
    cout << "Expression evaluated: " << expression << endl;
    //core loop:
    while(expression != "") {
        char next_op = expression[0];
        if (next_op == 40) {
            // 40 = '(' - we simply push
            operators.push(next_op);

        } else if (next_op == 41) {
            // 41 = ')' - we evaluate everything entered since the last '('
            if (current != "") {
                //last number parsed needs to also make it to the operand stack
                operands.push(stod(current));
                current = "";
            }
            while(!operators.empty() && operators.top() != 40) {
                //we evaluate until we hit the bottom or until the next opening parenthesis
                double val2 = operands.top();
                operands.pop();
                 
                double val1 = operands.top();
                operands.pop();
                 
                char op = operators.top();
                operators.pop();
                
                operands.push(evaluate(val1, val2, op));
            }
             
            // pop opening parenthesis
            if(!operators.empty())
               operators.pop();
               
        } else if(next_op < 48 && next_op != 46 || next_op == 94) {
            //if the next_op character is an operator, we add the current value of the number we were parsing

            if (current != "") {
                operands.push(stod(current));
                current = "";
            }


            //if the current operator is of higher priority than the top operator on the stack, we evaluate
            while(!operators.empty() && order(operators.top()) >= order(next_op)) {
                double val2 = operands.top();
                operands.pop();
                 
                double val1 = operands.top();
                operands.pop();
                 
                char op = operators.top();
                operators.pop();
                
                operands.push(evaluate(val1, val2, op));
            }
             
            // We push the current operator to operator stack.
            operators.push(next_op);

        } else {
            // otherwise, we have a digit or a decimal point, which we add to the current string.
            current += next_op;
        }

        //once the character is parsed, we shorten the string by the first char
        expression.erase(0, 1);
    }
    if (current != "") {
        //if there were no parentheses, the last number parsed has not yet been added to the operand stack - let's fix that.
        operands.push(stod(current));
    }

    double result = 0;

    while(!operators.empty()){
        //evaluate remaining values
        double val2 = operands.top();
        operands.pop();
                 
        double val1 = operands.top();
        operands.pop();
                 
        char op = operators.top();
        operators.pop();
                 
        operands.push(evaluate(val1, val2, op));
    }

    return operands.top();
}


bool is_math(char c) {
    //for use in string cleanup (first statement of infix_solver). returns true for any character NOT in the set
    // {+, -, *, /, ^, (, ), <numbers 0-9>}
    return c < 40 || c == 44 || c > 57 && c != 94;
}


int order (char op) {
    //order of precedence definer. exponents > mult/div > add/sub
    switch(op) {
        case PLUS:
            return 1;
        case MINUS:
            return 1;
        case MULT:
            return 2;
        case DIV:
            return 2;
        case POW:
            return 3;
        default:
            return 0;
    }
}