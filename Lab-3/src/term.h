#include <string>
#include <unordered_set>

using namespace std;

struct term {
    string term_id;
    bool is_spring; // attribute informing whether a given term is a spring term (1) or a fall term (0)
    unordered_set<string> courses;

    term() {}

    term (string term_id, string course, bool is_spring) {
        this->term_id = term_id;
        this->is_spring = is_spring;
        courses.insert(course);
    }

    void add_course(string course) {
        courses.insert(course);
    }

};
