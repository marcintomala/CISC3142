#include <string>
#include <vector>

using namespace std;

struct section {
    string class_id; // unique class id (term + courseno + section)
    string course_no; // e.g. 1115
    string section_code; // e.g. S04
    string instr_id; // e.g. I01
    string term; // e.g. T04
    vector<string> students; // list of student ids associated with given class instance

    section(string class_id, string course_no, string section_code, string instr_id, string term) {
        this->class_id = class_id;
        this->course_no = course_no;
        this->section_code = section_code;
        this->instr_id = instr_id;
        this->term = term;
    }

    void add_student(string emplid) {
        students.push_back(emplid);
    }
};
