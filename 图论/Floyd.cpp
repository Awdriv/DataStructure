#include <awdriv>

int mGraph[32][32] = {
    {INF, 5 ,INF, 7 },
    {INF,INF, 4 , 2 },
    { 3 , 3 ,INF, 2 },
    {INF,INF, 1 ,INF}
};

void floyd(int mGraph[32][32], int n, int agents[32][32]) {
    // 这个算法会改变邻接矩阵，需要备份
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            agents[i][j] = -1;               // 初始化 PATH
        }
    }
    // 这里不用判断是否存在相等，因为存在相等啥都不做
    for (int agent = 0; agent < n; agent++) {
        for (int from = 0; from < n; from++) {
            for (int to = 0; to < n; to++) {
                // 如果到自身距离表示为 0 则无需此判断
                if (agent == from || from == to || 
                    agent == to) {
                    continue;
                }
                // 计算中介者路径是否更短
                int d = mGraph[from][agent] +
                        mGraph[agent][to];
                if (d < mGraph[from][to]) {
                    mGraph[from][to] = d;
                    agents[from][to] = agent;
                }
            }
        }
    }
}

void findPath(int mGraph[32][32], int agents[32][32], int from, int to) {
    if (mGraph[from][to] == INF) {               // Floyd 处理后的 mGraph
        _sout("No Path!");                                      // 没有路
        return ;
    }
    int agent = agents[from][to];
    if (agent == -1) {
        _sout("(" << from << ", " << to << ")");        // 直达，直接输出
    } else {
        findPath(mGraph, agents, from, agent);  // 递归找起点到中介点的路
        findPath(mGraph, agents, agent, to);    // 递归找中介点到终点的路
    }
}

int main() {
    int agents[32][32];
    floyd(mGraph, 4, agents);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << agents[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    findPath(mGraph, agents, 1, 0);
}