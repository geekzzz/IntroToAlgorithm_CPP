//自己写的二叉搜索树，根据clrs伪代码
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>
#include <ctime>
#include <stdlib.h>
using namespace std;

class Node;
class BiSearchTree;

class Node
{
public:
    //Node(int n = 0,Node *l = NULL,Node *r = NULL,Node *p = NULL) : n(n),left(l),right(r),parent(p) {};
    int n;
    Node *parent;
    Node *left;
    Node *right;
};

class BiSearchTree
{
public:
    //BiSearchTree() = default;
    //BiSearchTree(Node *r) : root(r) {};
    Node *root = NULL;
    
    void inOrder_TreeWalk(Node *x); //中序遍历
    void firstOrder_TreeWalk(Node *x);//先序遍历
    void lastOrder_TreeWalk(Node *);//后续遍历
    Node *tree_search(Node *x,int k);//查找值为k的节点
    Node *iterative_tree_search(Node *x,int k);//使用while的查找
    Node *tree_minium(Node *x);//查找树最小值
    Node *tree_maxium(Node *x);//查找树最大值
    Node *iterative_treeminium(Node *x);//非递归最小值
    Node *iterative_treemaxium(Node *x);//非递归最大值
    Node *tree_successor(Node *x);//节点的后继
    Node *tree_predecessor(Node *x);//节点的前驱
    void tree_insert(Node *x);  //插入节点
    void tree_delete(Node *x);  //删除节点
    void transplant(Node *u,Node *v); //用一颗以v为根节点的子树替换以用u为根节点的子树
};

void BiSearchTree::inOrder_TreeWalk(Node *x)
{
    if(x != NULL)
    {
        inOrder_TreeWalk(x->left);
        cout << x->n << ":";
        inOrder_TreeWalk(x->right);
    }
}

void BiSearchTree::firstOrder_TreeWalk(Node *x)
{
    if(x != NULL)
    {
        cout << x->n << ":";
        firstOrder_TreeWalk(x->left);
        firstOrder_TreeWalk(x->right);
    }
}

void BiSearchTree::lastOrder_TreeWalk(Node *x)
{
    if(x != NULL)
    {
        lastOrder_TreeWalk(x->left);
        lastOrder_TreeWalk(x->right);
        cout << x->n << ":";
    }
}

Node *BiSearchTree::tree_search(Node *x, int k)
{
    if(x == NULL ||x->n == k)
    {
        return x;
    }
    if(k < x->n)
    {
        return tree_search(x->left, k);
    }
    else
    {
        return tree_search(x->right, k);
    }
}

Node *BiSearchTree::iterative_tree_search(Node *x, int k)
{
    while (x != NULL && x->n != k)
    {
        if(k < x->n)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    return x;
}

Node *BiSearchTree::tree_minium(Node *x)
{
    if(x->left != NULL)
    {
        return tree_minium(x->left);
    }
    else
    {
        return x;
    }
}

Node *BiSearchTree::tree_maxium(Node *x)
{
    if(x->right != NULL)
    {
        return tree_minium(x->right);
    }
    else
    {
        return x;
    }
}

Node *BiSearchTree::iterative_treeminium(Node *x)
{
    while(x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

Node *BiSearchTree::iterative_treemaxium(Node *x)
{
    while(x->right != NULL)
    {
        x = x->right;
    }
    return x;
}

/*
 1.若一个节点有右子树，那么该节点的后继节点是其右子树中val值最小的节点（也就是右子树中所谓的leftMostNode）
 2.若一个节点没有右子树，那么判断该节点和其父节点的关系
 2.1 若该节点是其父节点的左边孩子，那么该节点的后继结点即为其父节点
 2.2 若该节点是其父节点的右边孩子，那么需要沿着其父亲节点一直向树的顶端寻找，直到找到一个节点P，P节点是其父节点Q的左边孩子（可参考例子2的前驱结点是1），那么Q就是该节点的后继节点
 */
Node *BiSearchTree::tree_successor(Node *x) //
{
    if(x->right != NULL)
    {
        return tree_minium(x->right);
    }
    Node *y = new Node();
    y = x->parent;
    while(y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

/*
 1.若一个节点有左子树，那么该节点的前驱节点是其左子树中val值最大的节点（也就是左子树中所谓的rightMostNode）
 2.若一个节点没有左子树，那么判断该节点和其父节点的关系
 2.1 若该节点是其父节点的右边孩子，那么该节点的前驱结点即为其父节点。
 2.2 若该节点是其父节点的左边孩子，那么需要沿着其父亲节点一直向树的顶端寻找，直到找到一个节点P，P节点是其父节点Q的右边孩子（可参考例子2的前驱结点是1），那么Q就是该节点的后继节点
 */
Node *BiSearchTree::tree_predecessor(Node *x)
{
    if(x->left != NULL)
    {
        return tree_maxium(x->left);
    }
    Node *y = new Node();
    y = x->parent;
    while(y != NULL && x == y->left)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

void BiSearchTree::tree_insert(Node *z)
{
    Node *zz = new Node();  //！！！！！！！！注意要重新分配空间，不能直接用*z，否则会使用*z指向的地址数据，修改之前已经修改的数据
    zz->n = z->n;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;
    Node *y = NULL;
    Node *x = root;
    //cout << root;
    while(x != NULL)
    {
        y = x;
        if(zz->n < x->n)
        {
            x = x->left;  //x扫描y节点左右子树
        }
        else
        {
            x = x->right;  //x扫描y节点左右子树
        }
    }
    zz->parent = y;
    if(y == NULL)
    {
        root = zz;       //y为null，即树为空，z设为根节点
    }
    else if(zz->n < y->n)  //否则插入左或右子树
    {
        y->left = zz;
    }
    else
    {
        y->right = zz;
    }
}

void BiSearchTree::transplant(Node *u, Node *v)
{
    if(u->parent == NULL)
    {
        root = v;
    }
    else if(u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    if(v != NULL)
    {
        v->parent = u->parent;
    }
}

/*
 (1)  结点z无左右子树，则直接删除该结点，修改父节点相应指针
 (2)  结点z有左子树（右子树），则把z的左子树（右子树）接到z的父节点上
 (3)  左右子树同时存在，找到结点z的中序直接后继结点s，把结点s的数据转移到结点z，然后删除结点s，由于结点s为z的右子树总最左的结点，因而s无左子树，删除结点s可以归结到情况
 */
void BiSearchTree::tree_delete(Node *z)
{
    if(z->left == NULL)//处理没有左孩子的情况
    {
        transplant(z, z->right);
        
    }
    else if(z->right == NULL)//处理有左孩子没有右孩子的情况
    {
        transplant(z, z->left);
        
    }
    else     //处理z有两个孩子的剩下两种情况
    {
        Node *y =tree_minium(z->right);//找到y，用y替换删除的z
        if(y->parent != z)//若y->parent节点为z（即y为z的右子树），则只需要将y的左子树替换为z的左子树即可，不需要if内的操作
        {
            transplant(y, y->right);     //将z节点替换为y节点,右子树移植的操作
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(y, y->left);          //将z节点替换为y节点，左子树移植的操作
        y->left = z->left;
        y->left->parent = y;
    }
}

int  main(int argc,const char *argv[])
{
    BiSearchTree *tt = new BiSearchTree();
    int a[10] = {4,1,7,9,5,8,2,3,6,10};
    for(auto i = 0;i < 10;i++)
    {
        Node *z = new Node();
        z->n = a[i];
        tt->tree_insert(z);
    }
    tt->firstOrder_TreeWalk(tt->root);
    cout << endl;
    tt->inOrder_TreeWalk(tt->root);
    cout << endl;
    tt->lastOrder_TreeWalk(tt->root);
    cout << endl;
    
    //Node *xxx;
    Node *xxxx = tt->tree_search(tt->root, 5);
    cout << xxxx->n << endl;
    
    tt->tree_delete(tt->tree_search(tt->root, 5));
    tt->firstOrder_TreeWalk(tt->root);
    
    cout << tt->tree_minium(tt->root)->n << endl;
    /*
     tt->tree_delete(tt->tree_search(tt->root, 1));
     tt->firstOrder_TreeWalk(tt->root);
     cout << endl;
     tt->tree_delete(tt->tree_search(tt->root, 4));
     tt->firstOrder_TreeWalk(tt->root);
     */
}
