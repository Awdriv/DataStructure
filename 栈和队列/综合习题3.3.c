#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char op[]) {
    int stack_length = 0;
    for (int i = 0; i < strlen(op); i++) {
        char ch = op[i];
        if (ch == 'I') {
            ++stack_length;
        } else if (ch == 'O') {
            if (!stack_length) {
                return 0;
            }
            --stack_length;
        }
    }
    return !stack_length;
}

int main() {
    printf("%d\n", check("IOIOIOIIOO"));
    return 0; 
}