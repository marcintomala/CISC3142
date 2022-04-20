#include <iostream>
#include <unordered_map>
#include "section.h"
#include "student.h"
#include "instructor.h"


class college {
    unordered_map<string, student*> students;
    unordered_map<string, section*> courses;
    unordered_map<string, instructor*> instructors;

    public: 
    college() {};

    student* get_student(string emplid) {
        return students[emplid]; 
    }

    section* get_section(string class_id) {
        return courses[class_id];
    }

    instructor* get_instructor(string ins_id) {
        return instructors[ins_id]; 
    }

    void enroll_student(string emplid, string course, string grade) {
        if (!students.count(emplid)) {
            student* s = new student(emplid, course, grade);
            students[emplid] = s;
        } else {
            students[emplid]->add_course(course, grade);
        }
    }

    void assign_instructor(string ins_id, string course) {
        if (!instructors.count(ins_id)) {
            instructor* s = new instructor(ins_id, course);
            instructors[ins_id] = s;
        } else {
            instructors[ins_id]->add_course(course);
        }
    }

    void schedule_course(string course, section* sect) {
        courses[course] = sect;   
    }

    unordered_map<string, student*> get_students() {
        return students;
    }
    unordered_map<string, section*> get_courses() {
        return courses;
    }
    unordered_map<string, instructor*> get_instructors() {
        return instructors;
    }

};