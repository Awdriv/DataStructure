#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

int exec(float a, char op, float b, float *res) {
    //printf("%f %c %f\n", a, op, b);
    if (op == '+') *res = a + b;
    else if (op == '-') *res = a - b;
    else if (op == '*') *res = a * b;
    else if (op == '/') {
        if (fabs(b) < 1e-5) {
            printf("Divide Zero Error\n");
            return 0;
        }
        *res = a / b;
    }
    return 1;
}

int calc(char syntax[]) {
    float num[666], a, b, res;
    char op[233], ch;
    int t_num = 0, t_op = 0;
    for (int i = 0; i < strlen(syntax); i++) {
        ch = syntax[i];
        if (ch >= '0' && ch <= '9') {
            num[t_num++] = (float)(ch - '0');
        }
        if (ch == '(') {
            op[t_op++] = '(';
        }
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (t_op && op[t_op - 1] != '(') {
                // getPriority 忘写 x2，淦
                while (t_op && getPriority(ch) <= getPriority(op[t_op - 1])) {
                    b = num[--t_num]; a = num[--t_num];
                    if (!exec(a, op[--t_op], b, &res)) return 0;
                    else num[t_num++] = res;
                }
            }
            op[t_op++] = ch;
        }
        if (ch == ')') {
            char this_op;
            while ((this_op = op[--t_op]) != '(') {
                b = num[--t_num]; a = num[--t_num];
                if (!exec(a, this_op, b, &res)) return 0;
                else num[t_num++] = res;      
            }
        }
    }
    while (t_op) {
        b = num[--t_num]; a = num[--t_num];
        if (!exec(a, op[--t_op], b, &res)) return 0;
        else num[t_num++] = res;
    }
    printf("%f\n", num[t_num - 1]);
}

int main() {
    char syntax[1688];
    scanf("%s\n", syntax);
    calc(syntax);
}