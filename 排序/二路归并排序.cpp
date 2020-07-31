#include <awdriv>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1, n2 = high - mid;
    int a1[MAXSIZE], a2[MAXSIZE];
    // 复制数据到临时数组
    memcpy(a1, arr + low, n1 * sizeof(int));
    memcpy(a2, arr + mid + 1, n2 * sizeof(int));
    // 将共同区间的关键字合并
    int i1 = 0, i2 = 0, k = low;
    while (i1 < n1 && i2 < n2) {
        arr[k++] = a1[i1] <= a2[i2] ? a1[i1++] : a2[i2++];
    }
    // 追加剩余元素
    while (i1 < n1) {
        arr[k++] = a1[i1++];
    }
    while (i2 < n2) {
        arr[k++] = a2[i2++];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = { 1, 2, 45, 3, 56, 76, 342, 14, -34, -314 };
    mergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        _sout(arr[i]);
    }
    return 0;
}