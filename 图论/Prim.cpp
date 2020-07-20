#include <awdriv.h>

int mGraph[32][32] = {
    {INF, 5, 1, 2, INF},
    {5, INF, 3, INF, 4},
    {1, 3, INF, 6, 2},
    {2, INF, 6, INF, 3},
    {INF, 4, 2, 3, INF}
};

void prim(int mGraph[32][32], int n, int start, int *sum) {
    int cost[32];
    int vSet[32];
    for (int i = 0; i < n; i++) {
        cost[i] = mGraph[start][i];       // 到其他点的代价
        vSet[i] = 0;                        // 清空标记数组
    }
    vSet[start] = 1; *sum = 0;                  // 开始顶点
    for (int rev = 0; rev < n - 1; rev++) {
        int min = INF;
        int minId = -1;
         // 寻找最小代价的没去过的顶点
        for (int i = 0; i < n; i++) {
            if (!vSet[i] && cost[i] < min) {
                min = cost[i]; minId = i;
            }
        }
        // 将该点并入生成树，并累计代价
        start = minId; vSet[start] = 1; (*sum) += min;
        for (int i = 0; i < n; i++) {
            if (!vSet[i] && mGraph[start][i] < cost[i]) {
                // 针对新加入的点更新生成树到其他点的代价
                cost[i] = mGraph[start][i];
            }
        }
    }
}

int main() {
    int sum = 0;
    prim(mGraph, 5, 0, &sum);
    _sout(sum);
    return 0;
}