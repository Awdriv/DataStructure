#include <awdriv>

int is(int arr[], int n) {
    int min = INT_MIN, max = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min || arr[i] > max) {
            return 0;
        }
        if (i < n - 1) {
            ((arr[i + 1] > arr[i]) ? min : max) = arr[i];
        }
    }
    return 1;
}

int main() {
    int arr[] = {46, 36, 18, 28, 35};
    _sout(is(arr, sizeof(arr) / sizeof(int)));
    return 0;
}