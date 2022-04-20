#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <map>
#include "io.cpp"

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

map<string, vector<double>> rate_by_course(college* bc, bool (*criterion)(string)) {
    double hit;
    double total;
    double student_total = 0;
    string course_no;
    vector<double> hit_rate;
    map<string, vector<double>> per_course_rate;

    unordered_map<string, section*>* courses = bc->get_courses();
    unordered_map<string, student*>* students = bc->get_students();
    unordered_map<string, instructor*>* instructors = bc->get_instructors();

    for(const auto& c : *courses) {
        hit = 0;
        total = 0;
        hit_rate = {};
        course_no = c.second->course_no;
        for (const auto& s : c.second->students) {
            hit += criterion(students->at(s)->classes.at(c.first));
            total++;
        }

        if(per_course_rate.count(course_no)) {
            per_course_rate[course_no][0] += hit;
            per_course_rate[course_no][1] += total;
        } else {
            hit_rate.push_back(hit);
            hit_rate.push_back(total);
            per_course_rate[course_no] = hit_rate;
        }
        student_total += total;
    }

    vector<string> course_nos = {"1115", "3115", "3130"};
    for (string s : course_nos) {
        per_course_rate[s].push_back(per_course_rate[s][0] / per_course_rate[s][1]);
    }

    return per_course_rate;
}

map<string, vector<double>> rate_by_ins(college* bc, bool (*criterion)(string)) {
    double pass;
    double total;
    double student_total = 0;
    vector<double> p_rate;
    map<string, vector<double>> per_ins_rate;
    
    unordered_map<string, section*>* courses = bc->get_courses();
    unordered_map<string, student*>* students = bc->get_students();
    unordered_map<string, instructor*>* instructors = bc->get_instructors();
    
    for(const auto& i : *instructors) {
        pass = 0;
        total = 0;
        p_rate = {};
        for (const auto& c : i.second->classes) {
            for(string s : courses->at(c)->students) {
                pass += criterion(students->at(s)->classes[c]);
                total++;
            }
        }
        p_rate.push_back(pass);
        p_rate.push_back(total);
        p_rate.push_back(double (pass)/total);
        per_ins_rate[i.first] = p_rate;
        student_total += total;
    }
    cout << "Total records read: " << student_total << endl;
    return per_ins_rate;
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