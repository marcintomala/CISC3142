#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

bool passed(string grade) {
    unordered_set<string> passing = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "CR", "C-", "D+", "D", "D-", "P"};
    // Any grade below C- cannot be used to proceed with CS major - thus another category of failure
    return passing.count(grade);
}

bool withdrew(string grade) {
    unordered_set<string> withdrawals = {"W", "WN", "WD", "WU"};
    return withdrawals.count(grade);
}

bool cs_passed(string grade) {
    unordered_set<string> cs_passing = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "CR"};
    return cs_passing.count(grade);
}

int grade_to_number (string grade) {
    // randomized numerization function
    // input: valid letter grade (possibly with +/-)
    // output: randomized numerical value corresponding to it

    int numeric = 30;
    enum brackets {A = 65, B, C, D, F};
    enum plmn {PLUS = 43, MINUS = 45};

    switch(grade[0]) {
        case A:
            numeric += 65;
            break;
        case B:
            numeric += 55;
            break;
        case C:
            numeric += 45;
            break;
        case D:
            numeric += 35;
            break;
        default:
            break;
    }

    int plminoffset = (rand() % 2) + 3;

    if (numeric == 30) {
        numeric += ((rand() % 5) - 2) * 10;
    }

    if (grade.length() > 1) {
        switch(grade[1]) {
            case PLUS:
                numeric += plminoffset;
                break;
            case MINUS:
                numeric -= plminoffset;
                break;
            default:
                break;
        }
    } else {
        numeric += (rand() % 4) - 3;
    }

    return numeric;
}