#include <string>
#include <unordered_set>

using namespace std;

struct term {
    string term_id;
    string name;
    unordered_set<string> courses;

    term() {}

    term (string term_id, string course, string name = "lol") {
        this->term_id = term_id;
        this->name = name;
        courses.insert(course);
    }

    void add_course(string course) {
        courses.insert(course);
    }

};
