#include <awdriv>

typedef struct ArcNode {
    int index;
    ArcNode *next;
} ArcNode;

typedef struct {
    char data;
    int count; // 出度
    ArcNode *first;
} VNode;

ArcNode* getArcNode(int idx, ArcNode *next) {
    ArcNode *an = (ArcNode*)malloc(sizeof(ArcNode));
    an->index = idx;
    an->next = next;
    return an;
}

VNode getVNode(char data, int count, ArcNode *an) {
    VNode vn;
    vn.data = data;
    vn.count = count;
    vn.first = an;
    return vn;
}

// 邻接表存储结构下的拓扑排序
int topoSort(VNode list[], int n) {
    int stack[MAXSIZE], pStack = 0;
    int del = 0;
    // 找出所有入度为 0 的节点进栈
    for (int i = 0; i < n; i++) {
        if (!list[i].count) {
            stack[pStack++] = i;
        }
    }
    while (pStack) {
        int curIdx = stack[--pStack];
        // 访问并删除节点
        _sout(list[curIdx].data); del++;
        // 指向的所有节点入度 - 1
        ArcNode *p = list[curIdx].first;
        while (p) {
            int nextIdx = p->index;
            // -1 后若入度为空则入栈
            if (!(--list[nextIdx].count)) {
                stack[pStack++] = nextIdx;
            }
            p = p->next;
        }
    }
    // 删除节点数 = 总数即成功
    return del == n; 
};

int main() {
    VNode list[] = {
        getVNode('0', 0, getArcNode(1, getArcNode(2, NULL))),
        getVNode('1', 1, getArcNode(3, NULL)),
        getVNode('2', 1, getArcNode(3, NULL)),
        getVNode('3', 2, NULL)
    };
    topoSort(list, 4);
    return 0;
}