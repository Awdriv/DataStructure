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

BTNode* buildTree(char *pre, char *in, int L1, int R1, int L2, int R2) {
    if (L1 > R1) {                                     // 前序串处理完毕
        return NULL;
    }
    char rootValue = pre[L1];                              // 根节点的值
    int i = strchr(in, rootValue) - in;                // 子树根节点位置
    return createNode(
        rootValue,
        buildTree(pre, in, L1 + 1, L1 + i - L2, L2, i - 1),    // 左子树
        buildTree(pre, in, R1 + i - R2 + 1, R1, i + 1, R2)     // 右子树
    );
}

int main() {
    char pre[] = "ABCDEFGH";
    char in[] = "CBEDFAHG";
    BTNode* my_tree = buildTree(pre, in, 0, strlen(pre) - 1, 0, strlen(in) - 1);
    r_center(my_tree);
    return 0;
}