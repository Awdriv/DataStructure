#include <awdriv>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int center = arr[low];
    int i = low, j = high;
    while (i < j) {
        // 右往左找个小于等于 CENTER 的
        while (i < j && arr[j] > center) j--;
        if (i < j) {
            // J 成了新的空位
            arr[i] = arr[j];
            i++;
        }
        // 左往右找个大于 CENTER 的
        while (i < j && arr[i] <= center) i++;
        if (i < j) {
            // I 成了新的空位
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = center;
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

int main() {
    int arr[] = { 1, 2, 45, 3, 56, 76, 342, 14, -34, -314 };
    quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        _sout(arr[i]);
    }
    return 0;
}