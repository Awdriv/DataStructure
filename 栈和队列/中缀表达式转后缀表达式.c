#include <stdio.h>
#include <stdlib.h>

int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

void convert(char infix[], char opt[], int *top) {
    int i = 0;
    char tmp[233];
    int pTmp = 0;
    char ch = 0;
    while (ch = infix[i++]) {
        if (ch >= 'a' && ch <= 'z') {
            opt[(*top)++] = ch;
        } else if (ch == '(') {
            tmp[pTmp++] = '(';
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (pTmp && tmp[pTmp - 1] != '(') {
                while (pTmp && getPriority(ch) <= getPriority(tmp[pTmp - 1])) {
                    opt[(*top)++] = tmp[--pTmp];
                }
            }
            tmp[pTmp++] = ch;
        } else if (ch == ')') {
            char tch;
            while ((tch = tmp[--pTmp]) != '(') {
                opt[(*top)++] = tch;
            }  
        }
    }
    while (pTmp) {
        opt[(*top)++] = tmp[--pTmp];
    }
}

int main() {
    char ifx[666];
    char opt[233];
    int top = 0;
    
    scanf("%s\n", ifx);
    convert(ifx, opt, &top);
    opt[top] = 0;
    printf("%s\n", opt);
    return 0;
}