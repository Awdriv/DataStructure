// #define _NO_SOUT
#include <awdriv.h>

double my_sqrt(double A, double p, double e) {
    while (fabs(p * p - A) >= e) {
        _sout(p);
        p = (p + A / p) / 2;
    }
    return p;
}

int main() {
    printf("%f\n", my_sqrt(1048576, 1, 1e-10));
    return 0;
}