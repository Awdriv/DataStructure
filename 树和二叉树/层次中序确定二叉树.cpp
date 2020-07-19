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

int searchEx(char *src, char ch, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (src[i] == ch) {
            return i;
        }
    }
    return -1;
}

// 初始位置 [0, 长度 - 1]
BTNode* buildTree(char *level, char *in, int levelLength, int lIn, int rIn) {
    if (!levelLength) {                                  // 层次串处理完毕
        return NULL;
    }
    char rootValue = level[0];
    int pos = strchr(in, rootValue) - in;                  // 根节点在最前
    char leftLevel[MAXSIZE], rightLevel[MAXSIZE];        // 中序根节点位置
    int leftLevelLength = 0, rightLevelLength = 0;
    // 将 level 中属于左右子树的节点按顺序分成两个数组
    // 循环从 1 开始，忽略根节点
    for (int i = 1; i < levelLength; i++) {
        // 查找 level[i] 是否在中序根节点位置之前，如果是，就属于左子树
        if (searchEx(in, level[i], lIn, pos - 1) != -1) {
            leftLevel[leftLevelLength++] = level[i];   // 属于左子树的节点
        } else {
            rightLevel[rightLevelLength++] = level[i]; // 属于右子树的节点
        } 
    }
    return createNode(
        rootValue,
        buildTree(leftLevel, in, leftLevelLength, lIn, pos - 1),
        buildTree(rightLevel, in, rightLevelLength, pos + 1, rIn)
    );
}

int main() {
    char level[] = "ABGCDHEF";
    char in[] = "CBEDFAHG";
    BTNode* my_tree = buildTree(level, in, strlen(level), 0, strlen(in) - 1);
    r_center(my_tree);
    return 0;
}