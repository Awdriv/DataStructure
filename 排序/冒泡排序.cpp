#include <awdriv>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        int swaped = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swaped = 1;
            }
        }
        // 这趟没交换，已然有序
        if (!swaped) {
            return;
        }
    }
}

int main() {
    int arr[] = { 1, 2, 45, 3, 56, 76, 342, 14, -34, -314 };
    bubbleSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        _sout(arr[i]);
    }
    return 0;
}