#include <awdriv.h>

typedef struct BTNode {
    // 值
    char v;
    // 左右子树
    BTNode *l_c, *r_c;
} BTNode;

BTNode* createNode(char v, BTNode* l_c, BTNode* r_c) {
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    node->v = v;
    node->l_c = l_c;
    node->r_c = r_c;
    return node;
}

void r_center(BTNode *p) {
    if (p) {
        r_center(p->l_c);
        _sout(p->v);
        r_center(p->r_c);
    }
}

// 初始位置 [0, 长度 - 1]
BTNode* buildTree(char *post, char *in, int L1, int R1, int L2, int R2) {
    if (L1 > R1) {                                      // 后序串处理完毕
        return NULL;
    }
    char rootValue = post[R1];                            // 根节点在最后
    int i = strchr(in, rootValue) - in;                 // 中序根节点位置
    return createNode(
        rootValue,
        buildTree(post, in, L1, L1 - L2 + i - 1, L2, i - 1),    // 左子树
        buildTree(post, in, R1 - R2 + i, R1 - 1, i + 1, R2)     // 右子树
    );
}

int main() {
    char post[] = "CEFDBHGA";
    char in[] = "CBEDFAHG";
    BTNode* my_tree = buildTree(post, in, 0, strlen(post) - 1, 0, strlen(in) - 1);
    r_center(my_tree);
    return 0;
}