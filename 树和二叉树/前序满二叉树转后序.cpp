#include <awdriv.h>

void change(char *pre, char *post, int L1, int R1, int L2, int R2) {
    if (L1 > R1) return;
    post[R2] = pre[L1];
    int half = (R1 - L1) / 2;
    change(pre, post, L1 + 1, L1 + half, L2, L2 + half - 1);
    change(pre, post, L1 + half + 1, R1, L2 + half, R2 - 1);
}

int main() {
    char pre[] = "ABDECFG";
    char post[MAXSIZE];
    change(pre, post, 0, strlen(pre) - 1, 0, strlen(pre) - 1);
    for (int i = 0; i < strlen(pre); i++) {
        printf("%c", post[i]);
    }
}