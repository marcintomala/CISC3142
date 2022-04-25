#include "college.h"

// function definitions for the college class


//getters for individuals
student* college::get_student(string emplid) {
        return students[emplid]; 
}

section* college::get_section(string class_id) {
    return courses[class_id];
}

instructor* college::get_instructor(string ins_id) {
    return instructors[ins_id]; 
}

term* college::get_term(string term_id) {
    return terms[term_id];
}

// enrollment functions
void college::enroll_student(string emplid, string course, string grade) {
    //only unique students are added, otherwise they only have a new course added to them
    if (!students.count(emplid)) {
        student* s = new student(emplid, course, grade);
        students[emplid] = s;
    } else {
        students[emplid]->add_course(course, grade);
    }
}

void college::assign_instructor(string ins_id, string course) {
    //only unique instructors are added, otherwise they only have a new course added to them
    if (!instructors.count(ins_id)) {
        instructor* s = new instructor(ins_id, course);
        instructors[ins_id] = s;
    } else {
        instructors[ins_id]->add_course(course);
    }
}

void college::schedule_course(string course, section* sect) {
    //courses are uniquely identified, so there is nothing else to do than to add them
    courses[course] = sect;   
}

void college::schedule_term(string term_id, term* term) {
    terms[term_id] = term;
}

//to avoid passing big data structures around, getters return the address of the main college ds':
unordered_map<string, student*>* college::get_students() {
    return &students;
}
unordered_map<string, section*>* college::get_courses() {
    return &courses;
}
unordered_map<string, instructor*>* college::get_instructors() {
    return &instructors;
}
unordered_map<string, term*>* college::get_terms() {
    return &terms;
}
