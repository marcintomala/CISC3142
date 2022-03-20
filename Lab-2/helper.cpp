#include "helper.h"

double fast_powering (double a, int exp) {
    double result = 0;
    while (exp > 0) {
        if(exp & 1) {
            if (result) {
                result *= a;
            } else {
                result = a;
            }
        }
        exp >>= 1;
        a *= a;
    }
    return result;
}