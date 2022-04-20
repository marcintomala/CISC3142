#include <string>

using namespace std;

struct section {
    string course_num;
    string section_code;
    string instr_id;
    string term;

    section(string course_num, string section_code, string instr_id, string term) {
        this->course_num = course_num;
        this->section_code = section_code;
        this->instr_id = instr_id;
        this->term = term;
    }
};
