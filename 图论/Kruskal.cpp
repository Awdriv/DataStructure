#include <awdriv.h>
#include <algorithm>
#include <cmath>

typedef struct Road {
    int from;
    int to;
    int cost;
} Road;

Road* getRoad(int from, int to, int cost) {
    Road *road = (Road*)malloc(sizeof(Road));
    road->from = from;
    road->to = to;
    road->cost = cost;
    return road;
}

Road* road[] = {
    getRoad(0, 3, 2),
    getRoad(3, 4, 3),
    getRoad(4, 1, 4),
    getRoad(1, 0, 5),
    getRoad(1, 2, 3),
    getRoad(2, 3, 6),
    getRoad(0, 2, 1),
    getRoad(2, 4, 2)
};

int cmp(Road *a, Road *b) {
    return a->cost < b->cost;
}

int gRoot(int set[], int n) {
    while (n != set[n]) {
        n = set[n];
    }
    return n;
}

void kruskal(Road *road[], int roadCount, int *sum) {
    int querySet[32];               // 并查集用的数组
    (*sum) = 0;
    for (int i = 0; i < roadCount; i++) {
        querySet[i] = i;              // 初始化并查集
    }
    std::sort(road, road + roadCount, cmp);
    for (int i = 0; i < roadCount; i++) {
        int froot = gRoot(querySet, road[i]->from);
        int troot = gRoot(querySet, road[i]->to);
        if (froot != troot) {
            // 并查集拼接的是 ROOT！
            querySet[froot] = troot;
            (*sum) += road[i]->cost;
        }
    }
}

int main() {
    int sum;
    kruskal(road, 8, &sum);
    _sout(sum);
    return 0;
}