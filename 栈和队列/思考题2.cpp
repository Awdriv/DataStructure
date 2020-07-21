#include <awdriv>

void allsrt(char src[], char opt[], int used[], int pos, int length) {
    for (int i = 0;  i < length; i++) {
        if (used[i]) {
            continue;
        }
        
        used[i] = 1;
        opt[pos] = src[i];
        
        if (pos == length - 1) {
            printf("%s\n", opt);
        } else {
            allsrt(src, opt, used, pos + 1, length);
        }
        
        used[i] = 0;
    }
}

int main() {
    char opt[10086], src[] = "ABC";
    int used[10086], length = strlen(src);
    opt[length] = 0;
    memset(used, 0, sizeof(used));
    allsrt(src, opt, used, 0, length);
    return 0;
}