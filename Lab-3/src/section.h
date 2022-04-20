#include <string>
#include <vector>

using namespace std;

struct section {
    string class_id;
    string course_no;
    string section_code;
    string instr_id;
    string term;
    vector<string> students;

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
