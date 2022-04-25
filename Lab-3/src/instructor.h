#include <string>
#include <unordered_set>

using namespace std;

struct instructor {
    // instructor data consists of only id and courses they taught
    string ins_id;
    unordered_set<string> classes;  

    instructor (string ins_id, string course) {
        this->ins_id = ins_id;
        classes.insert(course);
    }
    
    void add_course(string course) {
        classes.insert(course);
    }
};