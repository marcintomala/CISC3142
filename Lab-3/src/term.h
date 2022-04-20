#include <string>

using namespace std;

struct term {
    string term_id;
    string name;

    term() {}

    term (string term_id, string name = "lol") {
        this->term_id = term_id;
        this->name = name;
    }
};
