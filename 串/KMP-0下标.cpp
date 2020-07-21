#include <awdriv>

void get_next_table(char *str, int length, int next[]) {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < length - 1) {
        if (j == -1 || str[i] == str[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int kmp(char *str, int length, char *sub, char sub_length, int next[]) {
    int i = 0, j = 0;
    while (i < length && j < sub_length) {
        if (j == -1 || str[i] == sub[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j = sub_length) {
        return i - sub_length;
    } else {
        return 0;
    }
}

int main() {
    int next[1024];
    char str[] = "1111100000";
    char sub[] = "ABABAAB";
    int length = strlen(str);
    int sub_length = strlen(sub);
    get_next_table(sub, sub_length, next);
    for (int i = 0; i < sub_length; i++) {
        printf("%d = %d\n", i, next[i]);
    }
    _sout(kmp(str, length, sub, sub_length, next));
    return 0;
}