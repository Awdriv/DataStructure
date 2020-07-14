#include <awdriv.h>

typedef struct bt_node {
    // 值
    char v;
    // 左右子树
    bt_node *l_c, *r_c;
} bt_node;

bt_node* g_n(char v, bt_node* l_c, bt_node* r_c) {
    bt_node *node = (bt_node*)malloc(sizeof(bt_node));
    node->v = v;
    node->l_c = l_c;
    node->r_c = r_c;
    return node;
}

bt_node* get_pre_def_tree() {
    // P144 例子那个树
    return g_n('A', g_n('B', g_n('C', NULL, NULL), g_n('D', g_n('E', NULL, NULL), g_n('F', NULL, NULL))), g_n('G', g_n('H', NULL, NULL), NULL));
}

// 递归算法 - 用于验证结论
void r_center(bt_node *p) {
    if (p) {
        r_center(p->l_c);
        _sout(p->v);
        r_center(p->r_c);
    }
}

void r_pre(bt_node *p) {
    if (p) {
        _sout(p->v);
        r_pre(p->l_c);
        r_pre(p->r_c);
    }
}

void r_after(bt_node *p) {
    if (p) {
        r_after(p->l_c);
        r_after(p->r_c);
        _sout(p->v);
    }
}

// 非递归算法
void ir_pre(bt_node *p) {
    bt_node *stack[1024];
    int p_stack = 0;
    if (p) {
        stack[p_stack++] = p;
    }
    while (p_stack) {
        bt_node *top = stack[--p_stack];
        _sout(top->v);
        if (top->r_c) {
            stack[p_stack++] = top->r_c;
        }
        if (top->l_c) {
            stack[p_stack++] = top->l_c;
        }
    }
}

void ir_right(bt_node *p) {
    bt_node *sa[1024], *sb[1024], *root = p;
    int p_sa = 0;
    int p_sb = 0;
    if (p) {
        sa[p_sa++] = p;
    }
    while (p_sa) {
        bt_node *top = sa[--p_sa];
        sb[p_sb++] = top;
        if (top->l_c) {
            sa[p_sa++] = top->l_c;
        }
        if (top->r_c) {
            sa[p_sa++] = top->r_c;
        }
    }
    while (p_sb) {
        _sout(sb[--p_sb]->v);
    }
}

void ir_center(bt_node *p) {
    bt_node *stack[1024];
    int p_stack = 0;
    while (p_stack || p) {
        while (p) {
            stack[p_stack++] = p;
            p = p->l_c;
        }
        if (p_stack) {
            bt_node *top = stack[--p_stack];
            _sout(top->v);
            p = top->r_c;
        }
    }
}

// BFS
void bfs(bt_node *p) {
    bt_node *queue[1024];
    int front = 0, rear = 0;
    if (!p) {
        return;
    }
    queue[++rear] = p;
    while (front != rear) {
        bt_node *cur = queue[front = (front + 1) % 1024];
        _sout(cur->v);
        if (cur->l_c) {
            queue[rear = (rear + 1) % 1024] = cur->l_c;
        }
        if (cur->r_c) {
            queue[rear = (rear + 1) % 1024] = cur->r_c;
        }
    }
}
int main() {
    bt_node *my_bt = get_pre_def_tree();
    bfs(my_bt);
    return 0;
}