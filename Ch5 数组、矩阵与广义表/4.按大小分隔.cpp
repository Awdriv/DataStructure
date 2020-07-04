#include <awdriv.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void split(int a[], int length) {
    int i = 0, j = length - 1;
    while (i < j) {
        if (a[i] >= a[j]) {
            if (j - i == 1) {
                swap(&a[i], &a[j]);
            } else {
                swap(&a[j], &a[j - 1]);
                swap(&a[i], &a[j]);
            }
            j--;
        } else if (a[i] < a[j]) {
            i++;
        }
    }
}

int main() {
    int a[] = { 8, 7, 6, 5, 4, 3, 2, 5 };
    split(a, 8);
    for (int i = 0; i < 8; i++) {
        _sout(a[i]);
    }
    return 0;
}