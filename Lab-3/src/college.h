#include <iostream>
#include <unordered_map>
#include <vector>
#include "section.h"
#include "student.h"
#include "instructor.h"
#include "term.h"


class college {
    // class and prototype functions for the college class
    unordered_map<string, student*> students;
    unordered_map<string, section*> courses;
    unordered_map<string, instructor*> instructors;
    unordered_map<string, term*> terms;

    public: 
    college() {};

    student* get_student(string emplid);
    section* get_section(string class_id);
    instructor* get_instructor(string ins_id);
    term* get_term(string term_id);

    void enroll_student(string emplid, string course, string grade);
    void assign_instructor(string ins_id, string course);
    void schedule_course(string course, section* sect);
    void schedule_term(string term_id, term* term);

    unordered_map<string, student*>* get_students();
    unordered_map<string, section*>* get_courses();
    unordered_map<string, instructor*>* get_instructors();
    unordered_map<string, term*>* get_terms();

};