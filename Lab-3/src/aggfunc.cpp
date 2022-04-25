#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <map>
#include "io.cpp"

using namespace std;


/* boolean functions that returns whether a grade is in one of the main three aggregation categories: */
bool passed(string grade) {
    unordered_set<string> passing = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "CR", "C-", "D+", "D", "D-", "P"};
    return passing.count(grade);
}

bool withdrew(string grade) {
    unordered_set<string> withdrawals = {"W", "WN", "WD", "WU"};
    return withdrawals.count(grade);
}

bool cs_passed(string grade) {
    // Any grade below C cannot be used to proceed with CS major - thus another category of failure
    unordered_set<string> cs_passing = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "CR"};
    return cs_passing.count(grade);
}


/* aggregation functions which return the mappings of category units to vector of {hit / attempt / ratio}:
   criterion is one of the filtering functions from above passed as a function pointer: */
map<string, vector<double>> rate_by_course(college* bc, bool (*criterion)(string)) {
    double hit;
    double total;
    double student_total = 0;
    string course_no;
    vector<double> hit_rate;
    map<string, vector<double>> per_course_rate;

    unordered_map<string, section*>* courses = bc->get_courses();
    unordered_map<string, student*>* students = bc->get_students();

    // for each course, we want to compute the number of students who passed/cs_passed/withdrew
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
    double hit;
    double total;
    double student_total = 0;
    vector<double> p_rate;
    map<string, vector<double>> per_ins_rate;
    
    unordered_map<string, section*>* courses = bc->get_courses();
    unordered_map<string, student*>* students = bc->get_students();
    unordered_map<string, instructor*>* instructors = bc->get_instructors();
    
    for(const auto& i : *instructors) {
        hit = 0;
        total = 0;
        p_rate = {};
        for (const auto& c : i.second->classes) {
            for(string s : courses->at(c)->students) {
                hit += criterion(students->at(s)->classes[c]);
                total++;
            }
        }
        p_rate.push_back(hit);
        p_rate.push_back(total);
        p_rate.push_back(double (hit)/total);
        per_ins_rate[i.first] = p_rate;
        student_total += total;
    }
    return per_ins_rate;
}


map<string, vector<double>> rate_by_term (college* bc, bool (*criterion)(string)) {
    double spring_hit = 0;
    double spring_total = 0;
    double fall_hit = 0;
    double fall_total = 0;
    double student_total = 0;
    vector<double> p_rate;
    map<string, vector<double>> per_term_rate = {
        {"Spring", {0, 0, 0}}, {"Fall", {0, 0, 0}}
    };
    
    unordered_map<string, section*>* courses = bc->get_courses();
    unordered_map<string, student*>* students = bc->get_students();
    unordered_map<string, term*>* terms = bc->get_terms();
    
    for(const auto& i : *terms) {
        p_rate = {};
        for (string c : i.second->courses) {
            for(string s : courses->at(c)->students) {
                if (i.second->is_spring) {
                    spring_hit += criterion(students->at(s)->classes[c]);
                    spring_total++;
                } else {
                    fall_hit += criterion(students->at(s)->classes[c]);
                    fall_total++;
                }
                student_total++;
            }
        }
    }
    per_term_rate["Spring"][0] = spring_hit;
    per_term_rate["Spring"][1] = spring_total;
    per_term_rate["Spring"][2] = spring_hit/spring_total;

    per_term_rate["Fall"][0] = fall_hit;
    per_term_rate["Fall"][1] = fall_total;
    per_term_rate["Fall"][2] = fall_hit/fall_total;

    return per_term_rate;
}


bool one_attempt(unordered_map<string, string>* courses) {
    // additional aggregation - how many of the students in the dataset have succeeded in
    // completing the intro sequence in one attempt each:
    unordered_set<string> course_nos;
    for (const auto& c : *courses) {
        string course_no = c.first.substr(4, 4);
        if(!course_nos.count(course_no)) {
            course_nos.insert(course_no);
        } else {
            return false;
        }
    }
    return course_nos.size() == 3;
}

bool straight_As(unordered_map<string, string>* courses) {
    // additional aggregation - how many of the students in the dataset have succeeded in 
    // passing each of the 3 courses with perfect GPA:
    unordered_set<string> course_nos;
    for (const auto& c : *courses) {
        string course_no = c.first.substr(4, 4);
        if(!course_nos.count(course_no) && (c.second == "A" || c.second == "A+")) {
            course_nos.insert(course_no);
        } else {
            return false;
        }
    }
    return course_nos.size() == 3;
}
