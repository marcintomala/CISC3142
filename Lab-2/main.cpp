#include "calculator.h"

void test();

int main() {
    test();
    //asks user for input then evaluates using infix_solver()
    string expression;
    cout << "Enter expression to evaluate (roots are handled as fractional powers, e.g. sqrt(2) -> 2^(1/2)): ";
    getline(cin >> ws, expression);
    cout << expression << endl;
    //exception handling, given that infix_solver throws a runtime error when the expression is empty
    try {
        Calculator calc {expression};
        double result = calc.infix_solver();
        cout << "Result: " << result << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

void test() {
    vector<string> test_vect = {
        //some basic tests
        "1 + 1",
        "(6+4)*(10-7)",
        "6+4*10-7",
        "6+(4*10)-7",
        "asgasd15-431",
        "2^(1/2)",
        "2^5" 
    };
    for (int i = 0; i < test_vect.size(); i++) {
        Calculator calc {test_vect[i]};
        double result = calc.infix_solver();
        cout << "Result: " << result << endl;
    }
    for (int n = 0; n < 15; n++) {
        // closed form Fibonacci
        string expr = "(1/5^(1/2))*(((1 + (5^(1/2)))/2)^" + to_string(n) + "-((1 - (5^(1/2)))/2)^" + to_string(n) + ")";
        Calculator calc {expr};
        double result = calc.infix_solver();
        cout << "Result: " << result << endl;
    }
}

