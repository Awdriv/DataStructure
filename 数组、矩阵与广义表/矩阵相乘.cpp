#include <awdriv>

void print_matrix(int mtx[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mtx[i][j]);
        }
        printf("\n");
    }
}

void mul_matrix(int mtx_a[][10], int mtx_b[][10], int mtx_c[][10], int m, int n, int k) {
    for (int i = 0; i < m; i++) { // 第 i 行
        for (int j = 0; j < k; j++) { // 第 j 列
            mtx_c[i][j] = 0;
            for (int p = 0; p < n; p++) {
                mtx_c[i][j] += mtx_a[i][p] /*A 的 i 行第 p 个元素*/ * mtx_b[p][j] /*B 的 j 列第 p 个元素*/;
            }
        }
    }
} 

int main() {
    int mtx_a[10][10] = {{1, 2, 3}, {4, 5, 6}};
    int mtx_b[10][10] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mtx_c[10][10] = { 0 };
    _sout("A");
    print_matrix(mtx_a, 2, 3);
    _sout("B");
    print_matrix(mtx_b, 3, 3);
    _sout("A*B");
    mul_matrix(mtx_a, mtx_b, mtx_c, 2, 3, 3);
    print_matrix(mtx_c, 2, 3);
    return 0;
}