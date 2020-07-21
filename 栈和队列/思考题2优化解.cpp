#include <awdriv>

// 1..N 个字符轮流与第 N 个字符交换
// 1..N-1 个字符轮流与第 N - 1 个字符交换
// 以此类推

void perm2(char src[], int length) {
    char temp;
    if (length == 1) {
        printf("%s\n", src);
        return;
    }
    
    int j = length - 1;
    for (int i = length - 1; i >= 0; i--) {
        temp = src[i];
        src[i] = src[j];
        src[j] = temp;
        perm2(src, length - 1);
        temp = src[i];
        src[i] = src[j];
        src[j] = temp;
    }
}

int main() {
    char src[] = "ABC";
    perm2(src, strlen(src));
    return 0;
}