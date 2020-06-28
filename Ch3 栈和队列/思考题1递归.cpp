#include <stdio.h>
#include <string.h>
#include <math.h>

double my_sqrt(double A, double p, double e) {
    if (fabs(p * p - A) < e) {
        return p;
    } else {
        return my_sqrt(A, (p + A / p) / 2, e);
    }
}

int main() {
    printf("%f\n", my_sqrt(1048576, 1, 1e-5));
    return 0;
}