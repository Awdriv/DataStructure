#include <awdriv>


typedef struct {
    int n;
} Graph;

void DFS(Graph g, int start, int visit[]) {

}

void BFS(Graph g, int start, int visit[]) {

}

// 图可能有零散的点
void dfsTravel(Graph g) {
    int visit[MAXSIZE];
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < g.n; i++) {
        if (!visit[i]) {
            // 和树的先序遍历差不多
            DFS(g, i, visit);
        }
    }
}

// 图可能有零散的点
void bfsTravel(Graph g) {
    int visit[MAXSIZE];
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < g.n; i++) {
        if (!visit[i]) {
            // 和树的 BFS 差不多
            BFS(g, i, visit);
        }
    }
}

int main() {
    
    return 0;
}