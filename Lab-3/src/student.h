#include <string>
#include <unordered_map>

using namespace std;

struct student { 
    string emplid;
    unordered_map<string, string> classes;

    student(string emplid, string course, string grade) {
        this->emplid = emplid;
        classes[course] = grade;
    }

    void add_course(string course, string grade) {
        classes[course] = grade;
    }
};
