#include "aggfunc.cpp"

int main () {
    college bc = read();
    map<string, double> pass_rate_ins = pass_rate_by_ins(&bc, &passed, "passed");
    map<string, double> withdraw_rate_ins = pass_rate_by_ins(&bc, &withdrew, "withdrew");
    return 0;
}

