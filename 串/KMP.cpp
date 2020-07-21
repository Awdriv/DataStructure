#include <awdriv>

void get_next_table(char *str, int length, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < length) {
        if (!j || str[i] == str[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int kmp(char *str, int length, char *sub, int sub_length, int next[]) {
    int i = 1, j = 1;
    while (i <= length && j <= sub_length) {
        if (!j || str[i] == sub[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > sub_length) {
        return i - sub_length;
    } else {
        return 0;
    }
}

int main() {
    int next[1024];
    char str[] = "_ASCXVSASC";
    char sub[] = "_XXVXX";
    int length = strlen(str) - 1;
    int sub_length = strlen(sub) - 1;
    get_next_table(sub, sub_length, next);
    for (int i = 1; i <= sub_length; i++) {
        printf("%d = %d\n", i, next[i]);
    }
    _sout(kmp(str, length, sub, sub_length, next));
    return 0;
}