#include <awdriv.h>

typedef struct BTNode {
    // 值
    char v;
    // 左右子树
    BTNode *l_c, *r_c;
} BTNode;

BTNode* g_n(char v, BTNode* l_c, BTNode* r_c) {
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    node->v = v;
    node->l_c = l_c;
    node->r_c = r_c;
    return node;
}

BTNode* get_pre_def_tree() {
    // P144 例子那个树
    return g_n('A', g_n('B', g_n('C', NULL, NULL), g_n('D', g_n('E', NULL, NULL), g_n('F', NULL, NULL))), g_n('G', g_n('H', NULL, NULL), NULL));
}

// 递归算法 - 用于验证结论
void r_center(BTNode *p) {
    if (p) {
        r_center(p->l_c);
        _sout(p->v);
        r_center(p->r_c);
    }
}

void r_pre(BTNode *p) {
    if (p) {
        _sout(p->v);
        r_pre(p->l_c);
        r_pre(p->r_c);
    }
}

void r_after(BTNode *p) {
    if (p) {
        r_after(p->l_c);
        r_after(p->r_c);
        _sout(p->v);
    }
}

// 非递归算法
void pre_dfs_ir(BTNode *p) {
    BTNode *stack[MAXSIZE];
    int p_stack = 0;
    if (p) stack[p_stack++] = p;
    while (p_stack) {
        BTNode *top = stack[--p_stack];
        _sout(top->v);
        if (top->r_c) stack[p_stack++] = top->r_c;
        if (top->l_c) stack[p_stack++] = top->l_c;
    }
}

void post_dfs_ir(BTNode *p) {
    BTNode *sa[MAXSIZE], *sb[MAXSIZE];
    int p_sa = 0, p_sb = 0;
    if (p) sa[p_sa++] = p; 
    while (p_sa) {
        BTNode *top = sa[--p_sa];
        sb[p_sb++] = top;
        if (top->l_c) sa[p_sa++] = top->l_c;
        if (top->r_c) sa[p_sa++] = top->r_c;
    }
    while (p_sb) {
        _sout(sb[--p_sb]->v);
    }
}

void in_dfs_ir(BTNode *p) {
    BTNode *stack[MAXSIZE];
    int p_stack = 0;
    while (p_stack || p) {
        while (p) {
            stack[p_stack++] = p;
            p = p->l_c;
        }
        if (p_stack) {
            BTNode *top = stack[--p_stack];
            _sout(top->v);
            p = top->r_c;
        }
    }
}

// BFS
void bfs(BTNode *p) {
    BTNode *queue[MAXSIZE];
    int front = 0, rear = 0;
    if (p) queue[++rear] = p;
    while (front != rear) {
        BTNode *cur = queue[++front % MAXSIZE];
        _sout(cur->v);
        if (cur->l_c) queue[++rear % MAXSIZE] = cur->l_c;
        if (cur->r_c) queue[++rear % MAXSIZE] = cur->r_c;
    }
}


int main() {
    BTNode *my_bt = get_pre_def_tree();
    pre_dfs_ir(my_bt);
    return 0;
}