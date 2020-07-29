#include <awdriv>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sift(int arr[], int low, int high) {
    int i = low, j = 2 * i + 1;
    while (j <= high) {
        // 这里 J 必定指向左子
        // 若右子比左子大且没出界，指向右子
        if (j < high && arr[j] < arr[j + 1]) j++; 
        // 当前节点比子节点小
        // 交换后需要处理被交换子节点的孔
        if (arr[i] < arr[j]) {
            swap(&arr[i], &arr[j]);
            i = j;
            j = 2 * i + 1;
        } else {
            // 左右子都比当前节点小
            // 结构正确，终止循环
            break;
        }
    }
}
void heapSort(int arr[], int n) {
    // 从最后一个非叶节点开始调整堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        sift(arr, i, n);
    }
    // 至此，堆构建完成，开始排序
    // 根节点进入有序序列后调整堆
    for (int i = n; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        sift(arr, 0, i - 1);
    }
}

int main() {
    int arr[] = { 1, 2, 45, 3, 56, 76, 342, 14, -34, -314 };
    heapSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        _sout(arr[i]);
    }
    return 0;
}