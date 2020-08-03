#include <awdriv>

int bSearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        // 第一次闭着眼睛写把这个写到循环外面去了淦
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
} 

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    _sout(bSearch(arr, 0, 7, 5));
    return 0;
}