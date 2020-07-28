#include <awdriv>

void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int tmp = arr[i];
        int j = i - 1;
        // 从右往左确定插入位置
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        // 注意这里是 J + 1
        arr[j + 1] = tmp;
    }
}

int main() {
    int arr[] = { 1, 2, 45, 3, 56, 76, 342, 14, -34, -314 };
    insertSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        _sout(arr[i]);
    }
    return 0;
}