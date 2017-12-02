//顺序统计树，没有实现全部功能，其他功能见红黑树代码，根据clrs伪代码实现
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>
#include <ctime>
#include <stdlib.h>

#define black 1
#define red 0

using namespace std;

class Node;
class BiSearchTree;

class Node
{
public:
    //Node(int n = 0,Node *l = NULL,Node *r = NULL,Node *p = NULL) : n(n),left(l),right(r),parent(p) {};
    int n;
    int color = black;  //红黑树，红为0，黑为1
    int size = 1;
    Node *parent;
    Node *left;
    Node *right;
};

class RB
{
public:
    RB()
    {
        nil = new Node();
        nil->size = 0;
    }
    
    Node *root = NULL;
    Node *nil = NULL;//哨兵节点
    
    void inOrder_TreeWalk(Node *x);
    void firstOrder_TreeWalk(Node *x);
    void lastOrder_TreeWalk(Node *x);
    Node *tree_search(Node *x, int k);
    void left_rotate(Node *x);//左旋
    void right_rotate(Node *x);//右旋
    void rb_insert(Node *z);//插入
    void rb_insert_fixup(Node *z);//保持插入后红黑性质
    void transplant(Node *u,Node *v);//移植
    Node *tree_minium(Node *x);//求最小数
    void rb_delete(Node *z);//删除节点
    void rb_delete_fixup(Node *x);//保持删除后红黑性质
    Node *os_select(Node *x, int i);
    int os_rank(Node *x);
    
};

//选择第i大的数据
Node* RB::os_select(Node *x, int i)
{
    int r = x->left->size +1;
    if(i == r)
    {
        return x;
    }
    else if(i<r)
    {
        return os_select(x->left, i);
    }
    else
    {
        return os_select(x->right, i);
    }
}

//求x在树中的秩，即：求出x在树中序遍历对应的线性序中的位置
int RB::os_rank(Node *x)
{
    int r = x->left->size+1;
    Node *y = new Node();
    while(y != root)
    {
        if(y == y->parent->right)
        {
            r = r + y->parent->left->size + 1;
        }
        y = y->parent;
    }
    return r;
}


void RB::left_rotate(Node *x)
{
    Node *y = new Node();
    y = x->right;
    x->right = y->left;
    if(y->left != nil)   //y的左节点不为nil的情况（即不为叶子节点的情况）
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nil)
    {
        root = y;
    }
    else if(x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->size = x->size;
    x->size = x->left->size + x->right->size + 1;
}

void RB::right_rotate(Node *x)
{
    Node *y = new Node();
    y = x->left;
    x->left = y->right;
    if(y->right != nil)   //y的右节点不为nil的情况（即不为叶子节点的情况）
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nil)
    {
        root = y;
    }
    else if(x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->size = x->size;
    x->size = x->left->size + x->right->size + 1;
}
