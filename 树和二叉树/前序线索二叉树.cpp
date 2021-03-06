#include <awdriv>

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

// 全局变量代替递归二级指针
// 调用函数前需要手动归零！
tbt_node* pre;
void build_pre_tree(tbt_node *p) {
    if (!p) return;
    if (!p->l_c) {
        p->l_c = pre;
        p->l_tag = 1;
    }
    if (pre && !pre->r_c) {
        pre->r_c = p;
        pre->r_tag = 1;
    }
    pre = p;
    // 非线索指针才进入递归
    // 否则会进入无限套娃模式
    if (!p->l_tag) build_pre_tree(p->l_c);
    if (!p->r_tag) build_pre_tree(p->r_c);
}

void enum_pre(tbt_node *p) {
    while (p) {
        while (!p->l_tag) {
            _sout(p->v);
            p = p->l_c;
        }
        _sout(p->v);
        p = p->r_c;
    }
}

tbt_node* find_next(tbt_node* p) {
    if (!p->l_tag && p->l_c) {
        return p->l_c;
    } else if (p->r_c) {
        return p->r_c;
    }
    return NULL;
}

int main() {
    tbt_node *root = get_pre_def_tree(), *p = root;
    pre = NULL;
    build_pre_tree(root);
    // enum_pre(root);
    while (p) {
        _sout(p->v);
        p = find_next(p);
    }
    return 0;
}