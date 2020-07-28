#include <awdriv>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void simpleSelectSort(int arr[], int n) {
    // 注意这里是 N - 1
    for (int i = 0; i < n - 1; i++) {
        int min = INT_MAX;
        int minId = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minId = j;
            }
        }
        swap(&arr[i], &arr[minId]);
    }
}

int main() {
    int arr[] = { 1, 2, 45, 3, 56, 76, 342, 14, -34, -314 };
    simpleSelectSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        _sout(arr[i]);
    }
    return 0;
}