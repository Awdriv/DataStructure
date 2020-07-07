#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int i = strlen(infix);
    char tmp[233];
    int pTmp = 0;
    char ch = 0;
    while (i--) {
        ch = infix[i];
        if (ch >= 'a' && ch <= 'z') {
            opt[(*top)++] = ch;
        } else if (ch == ')') {
            tmp[pTmp++] = ')';
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (pTmp && tmp[pTmp - 1] != '(') {
                while (pTmp && getPriority(ch) < getPriority(tmp[pTmp - 1])) {
                    opt[(*top)++] = tmp[--pTmp];
                }
            }
            tmp[pTmp++] = ch;
        } else if (ch == '(') {
            char tch;
            while ((tch = tmp[--pTmp]) != ')') {
                opt[(*top)++] = tch;
            }  
        }
    }
    while (pTmp) {
        opt[(*top)++] = tmp[--pTmp];
    }
}

int main() {
    int top = 0;
    char ifx[666], opt[233];
    
    scanf("%s\n", ifx);
    convert(ifx, opt, &top);
    
    for (int i = top - 1; i >= 0; i--) {
        printf("%c", opt[i]);
    }
    
    return 0;
}