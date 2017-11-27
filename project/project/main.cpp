//二叉搜索树
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
    int color;  //红黑树，红为0，黑为1
    Node *parent;
    Node *left;
    Node *right;
};

class RB
{
public:
    //BiSearchTree() = default;
    RB()
    {
        root->color = black;
    };
    Node *root = NULL;
    Node *nil = NULL;//哨兵节点
    
    
    void left_rotate(Node *x);//左旋
    void right_rotate(Node *x);//右旋
    void rb_insert(Node *z);//插入
    void rb_insert_fixup(Node *z);//保持插入后红黑性质
    void transplant(Node *u,Node *v);//移植
    Node *tree_minium(Node *x);//求最小数
    void rb_delete(Node *z);//删除节点
    void rb_delete_fixup(Node *x);//保持删除后红黑性质
    
    
};

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
}

void RB::rb_insert(Node *z)
{
    Node *zz = new Node();  //！！！！！！！！注意要重新分配空间，不能直接用*z，否则会使用*z指向的地址数据，修改之前已经修改的数据
    zz->n = z->n;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;
    Node *y = NULL;
    Node *x = root;
    while(x != nil)
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
    if(y == nil)
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
    zz->left = nil;
    zz->right = nil;
    zz->color = red;
}

void RB::rb_insert_fixup(Node *z)
{
    while(z->parent->color == red)
    {
        if(z->parent == z->parent->parent->left)//将z的父节点是祖父节点的左孩子还是右节点分类讨论
        {
            Node *y = new Node();
            y = z->parent->parent->right;//y指向z的叔节点
            if(y->color == red)     //若y的颜色为红，即z的叔节点为红，即区分情况1
            {
                z->parent->color = black;   //z的父节点颜色设为黑
                y->color = black;     //z的叔节点设为黑
                z->parent->parent->color = red;//祖父节点设为红
                z = z->parent->parent; //z改变指向，指向z的祖父节点
            }
            else
            {
                //叔结点为黑色
                ///此时要根据z是其父结点的左孩子还是右孩子进行分类讨论
                ///如果z是左孩子则可以直接可以通过染色和右旋来恢复性质
                ///如果z是右孩子则可以先左旋来转成右孩子的情况
                if(z == z->parent->right) //区分情况2，3，即在z的叔节点是black的情况下，区分z是右孩子还是左孩子
                {
                    z = z->parent;//是右孩子的情况，进行左旋,变为左孩子情况
                    left_rotate(z);
                }
                z->parent->color = black;//重新染色，右旋得到合法的树
                z->parent->parent->color = red;
                right_rotate(z->parent->parent);
            }
        }
        else       //z的父节点是z的祖父节点的右孩子的情况，与左孩子情况对称
        {
            Node *y = new Node();
            y = z->parent->parent->left;
            if(y->color == red)
            {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else
            {
                if(z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                left_rotate(z->parent->parent);
            }
        }
    }
    root->color = black;
}
///红黑树删除函数
///类似于二叉树删除函数,不过在删除完成以后需要调用调整函数恢复性质
///总的过程也是按z的左右儿子情况进行分类.
///1.z只有左儿子/右儿子
///2.z有左右儿子,要删除的结点是z的右儿子
///3.z有左右儿子,要删除的结点不是z的右儿子
void RB::rb_delete(Node *z)
{
    Node *y = new Node();
    y = z;
    int y_origin_color = y->color; //记录y原颜色
    Node *x = new Node();
    if(z->left == nil)      //只有右子树
    {
        x = z->right;     //直接移植，x记录z->right，最后与z比较颜色
        transplant(z, z->right);
    }
    else if(z->right == nil)//只有左子树
    {
        x = z->left;     //直接移植
        transplant(z, z->left);
    }
    else             //左右儿子都有
    {
        y = tree_minium(z->right);   //查找后继
        y_origin_color = y->color;   
        x = y->right;
        if(y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if(y_origin_color == black)
    {
        rb_delete_fixup(x);
    }
}



void RB::transplant(Node *u, Node *v)//与二叉搜索树相比改变不大
{
    if(u->parent == nil)
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


int  main(int argc,const char *argv[])
{
    
}
