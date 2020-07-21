#include <awdriv>

void move(int a[], int length) {
    int i = 0, j = length - 1;
    while (i < j) {
        if (!a[i] && a[j]) {
            a[i] = a[j];
            a[j] = 0;
            i++;
            j--;
        } else if (a[i]) {
            i++;
        } else if (!a[j]) {
            j--;
        }
    }
}

int main() {
    int a[] = { 1, 0, 2, 0, 5, 4, 0, 0 };
    move(a, 6);
    for (int i = 0; i < 6; i++) {
        _sout(a[i]);
    }
    return 0;
}