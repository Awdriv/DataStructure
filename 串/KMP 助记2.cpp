#include <awdriv>

int kmp(char *str, int length, char *sub, int subLength, int nextVal[]) {
    // I, J 分别为字符串和查找串的第一个字符下标
    int i = 1, j = 1;


    while (i <= length && j <= subLength) {
        if (!j || str[i] == sub[j]) {
            ++i;
            ++j;


        } else {
            j = nextVal[j];
        }
    }
    if (j > subLength) { // 查找 J 溢出，查找成功
        return i - subLength;
    } else {
        return 0;
    }
}