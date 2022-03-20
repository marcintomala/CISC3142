#include "helper.h"



struct Calculator {
    enum oper {PLUS = 1, MINUS, MULT, DIV, POW, SQRT};
    double op1;
    double op2;

    Calculator() {};

    Calculator(double op1, double op2) {
        this->op1 = op1;
        this->op2 = op2;
    }

    double calculate(int mode) {
        switch(mode) {
            case PLUS:
                return op1 + op2;
                break;
            case MINUS:
                return op1 - op2;
                break;
            case MULT:
                return op1 * op2;
                break;
            case DIV:
                if (op2) {
                    return op1 / op2;
                } else {
                    throw runtime_error("Math error: Attempted to divide by Zero\n");
                }
                break;
            case POW:
                return fast_powering(op1, op2);
                break;
            case SQRT:
                if (op1 >= 0) {
                    return sqrt(op1);
                } else {
                    throw runtime_error("Real square roots only!\n");
                }
                break;
            default:
                return 0;
        }
    }
};


int main() {
    cout << "Available modes:\n" 
    << "1 - Addition\n" << "2 - Subtraction\n" 
    << "3 - Multiplication\n" << "4 - Division\n"
    << "5 - Exponentiation\n" << "6 - Square Root\n"; 
    cout << "Enter mode: ";
    int mode;
    cin >> mode;
    cout << "Enter a number: ";
    double num1;
    cin >> num1;
    Calculator calc;
    if (mode < 6) {
        double num2;
        cout << "Enter another number: ";
        cin >> num2;
        calc = {num1, num2};
    } else {
        calc = {num1, 1/2};
    }

    try {
        double result = calc.calculate(mode);
        cout << "The result is " << result << endl;
    } catch(runtime_error& e) {
        cout << "An error has occured" << endl << e.what();
    }

    return 0;
}

