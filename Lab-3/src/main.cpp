#include "aggfunc.cpp"

void print_rate(map<string, vector<double>>* aggregate, string criterion1, string criterion2) {
    cout << "---------" << criterion1 << " RATE BY " << criterion2 << "---------" << endl;
    for (const auto& i : *aggregate) {
        cout << i.first << ": ";
        for (double r : i.second) {
            cout << r << "; ";
        }
        cout << endl;
    }
}

int main () {
    college bc = read();
    map<string, vector<double>> pass_rate_ins = rate_by_ins(&bc, &passed);
    map<string, vector<double>> withdraw_rate_ins = rate_by_ins(&bc, &withdrew);
    map<string, vector<double>> pass_rate_course = rate_by_course(&bc, &passed);
    map<string, vector<double>> withdraw_rate_course = rate_by_course(&bc, &withdrew);

    print_rate(&pass_rate_ins, "PASS", "INSTRUCTOR");
    print_rate(&withdraw_rate_ins, "WITHDRAW", "INSTRUCTOR");
    print_rate(&pass_rate_course, "PASS", "COURSE");
    print_rate(&withdraw_rate_course, "WITHDRAW", "COURSE");

    return 0;
}

