//带哨兵的双向链表的简单实现，根据clrs
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>
#include <ctime>
#include <stdlib.h>
using namespace std;
struct Head;
struct Double_list;
struct Node;

class Node;
class L;

class Node
{
public:
    friend class L;
    Node(int n = 0,Node *pre = NULL,Node *next = NULL) : n(n),pre(pre),next(next){}
    
    Node *pre ,*next;
    int n ;
};


class L
{
public:
    L()                          //一定要注意在同一个cpp文件中class的放置顺序，若class Node放在class L的后面，则此处编译会出问题
    {
        nil = new Node();      //一定要new 一个Node 否则会出错
        nil->pre = nil;       //一定要初始化nil的pre和next指向自己
        nil->next = nil;
    }
    void list_insert(Node *x);
    Node *list_search(int k);
    void list_delete(Node *x);
    
    Node  *nil ;
};



Node *L::list_search(int k)
{
    Node *x = NULL;
    x = nil->next;
    while(x != nil && x->n != k)
    {
        x = x->next;
    }
    return x;
}


void L::list_insert(Node *x)
{
    /*
    if(nil->next == NULL)
    {
        nil->next = nil;
    }
    if(nil->pre == NULL)
    {
        nil->pre = nil;
    }
     */
    x->next = nil->next;
    nil->next->pre = x;
    nil->next = x;
    x->pre = nil;
}

void L::list_delete(Node *x)
{
    x->pre->next = x->next;
    x->next->pre = x->pre;
}

int  main(int argc,const char *argv[])
{
    L *list  = new L();
    for(int i = 0;i< 10;i++)
    {
        Node *p = new Node();
        p->n = i;
        list->list_insert(p);
    }
    /*
    Node *p = list->head->next;
    for(int i = 0;i < 10;i++)
    {
        
        if(p != NULL)
        {
            cout << p->n << endl;
            p = p->next;
        }
    }
     */
    cout << endl;
    for(int i = 0;i< 10 ;i++)
    {
        Node *m = list->list_search(i);
        cout << m->n << endl;
    }
    
    list->list_delete(list->list_search(5));
    list->list_delete(list->list_search(8));
    cout << endl;
    for(int i = 0;i< 10 ;i++)
    {
        Node *m = list->list_search(i);
        if( m != NULL)
        {
            cout << m->n << endl;
        }
        
    }
}
