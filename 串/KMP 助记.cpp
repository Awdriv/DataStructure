#include <awdriv>

void getNextVal(char *str, int length, int nextVal[]) {
    // I 为第一个字符下标，J 为标记值即 I 之前一个位置
    int i = 1, j = 0;
    // 将第一个字符所在的 NV 设为标记值，查找没这玩意
    nextVal[1] = 0;
    while (i < length) { // 确保 i + 1 不溢出
        if (!j || str[i] == str[j]) {
            ++i;
            ++j;
            // 如果相等，激情套娃；求 Next 就直接赋值 J 即可
            nextVal[i] = (str[i] != str[j]) ? j : nextVal[j];
        } else {
            j = nextVal[j];
        }
    }
}

int kmp(char *str, int length, char *sub, int subLength, int nextVal[]) {
    // I, J 分别为字符串和查找串的第一个字符下标
    int i = 1, j = 1;
    while (i <= length && j <= subLength) {
        if (!j || str[i] == sub[j]) {
            ++i; ++j;
        } else {
            j = nextVal[j];
        }
    }
    if (j > subLength) { // 查找 J 越界则查找成功，I 越界则失败
        return i - subLength;
    } else {
        return 0;
    }
}

int main() {
    int nextVal[1024];
    char str[] = "_ASCXVSASC";
    char sub[] = "_XVS";
    int length = strlen(str) - 1;
    int subLength = strlen(sub) - 1;
    getNextVal(sub, subLength, nextVal);
    for (int i = 1; i <= subLength; i++) {
        printf("%d = %d\n", i, nextVal[i]);
    }
    _sout(kmp(str, length, sub, subLength, nextVal));
    return 0;
}