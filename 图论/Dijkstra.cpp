#include <awdriv>

int mGraph[32][32] {
//   0   1   2   3   4   5   6
   {INF, 4 , 6 , 6 ,INF,INF,INF}, // 0
   {INF,INF, 1 ,INF, 7 ,INF,INF}, // 1
   {INF,INF,INF,INF, 6 , 4 ,INF}, // 2
   {INF,INF, 2 ,INF,INF, 5 ,INF}, // 3
   {INF,INF,INF,INF,INF,INF, 6 }, // 4
   {INF,INF,INF,INF, 1 ,INF, 8 }, // 5
   {INF,INF,INF,INF,INF,INF,INF}  // 6
};

void dijkstra(int mGraph[32][32], int n, int start, int dist[], int path[]) {
    int set[32];
    for (int i = 0; i < n; i++) {
        set[i] = 0;
        dist[i] = mGraph[start][i];
        path[i] = mGraph[start][i] < INF ? start : -1;
    }
    set[start] = 1;                                     // 初始顶点并入最短路
    for (int rev = 0; rev < n - 1; rev++) {
        int min = INF, v = -1;      // 找一个离起点最近的顶点，v 保存顶点下标
        for (int i = 0; i < n; i++) {
            if (!set[i] && dist[i] < min) {
                min = dist[i]; v = i;
            }
        }
        set[v] = 1;
        for (int i = 0; i < n; i++) {
            int newDistance = mGraph[v][i] + dist[v];
            if (!set[i] && newDistance < dist[i]) {               // 核心步骤
                path[i] = v;                                      // 更新路径
                dist[i] = newDistance;                            // 更新距离
            }
        }
    }
}

int main() {
    int dist[32];
    int path[32];
    dijkstra(mGraph, 7, 0, dist, path);
    for (int i = 0; i < 7; i++) {
        _sout(dist[i]);
    }
    return 0;
}