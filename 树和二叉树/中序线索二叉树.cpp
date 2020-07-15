#include <awdriv.h>

typedef struct tbt_node {
    char v;
    int l_tag, r_tag;
    tbt_node *l_c, *r_c;
} tbt_node;

tbt_node* g_n(char v, tbt_node* l_c, tbt_node* r_c) {
    tbt_node *node = (tbt_node*)malloc(sizeof(tbt_node));
    node->v = v;
    node->l_c = l_c;
    node->r_c = r_c;
    node->l_tag = 0;
    node->r_tag = 0;
    return node;
}

tbt_node* get_pre_def_tree() {
    // P144 例子那个树
    return g_n('A', g_n('B', g_n('C', NULL, NULL), g_n('D', g_n('E', NULL, NULL), g_n('F', NULL, NULL))), g_n('G', g_n('H', NULL, NULL), NULL));
}

// 和中序的构造仅仅是顺序不同
// 全局变量代替递归二级指针
// 调用函数前需要手动归零！
tbt_node* pre;
void build_in_tree(tbt_node *p) {
    if (!p) return;
    build_in_tree(p->l_c);
    build_in_tree(p->r_c);
    if (!p->l_c) {
        p->l_c = pre;
        p->l_tag = 1;
    }
    if (pre && !pre->r_c) {
        pre->r_c = p;
        pre->r_tag = 1;
    }
    pre = p;
}

tbt_node* find_first(tbt_node *p) {
    while (!p->l_tag && p->l_c) {
        p = p->l_c;
    }
    return p;
}

tbt_node* find_next(tbt_node *p) {
    if (p->r_tag) {
        return p->r_c;
    } else {
        return find_first(p->r_c);
    }
}

int main() {
    tbt_node *p, *root = get_pre_def_tree();
    pre = NULL;
    build_in_tree(root);
    p = find_first(root);
    while (p) {
        _sout(p->v);
        p = find_next(p);
    }
    return 0;
}