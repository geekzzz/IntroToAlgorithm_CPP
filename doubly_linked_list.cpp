//双向链表的简单实现，根据clrs
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

class L
{
public:
    L(Node *head = NULL) : head(head) {}
    
    void list_insert(Node *x);
    Node *list_search(int k);
    void list_delete(Node *x);
    
    Node  *head = NULL;
};

class Node
{
public:
    friend class L;
    Node(int n = 0,Node *pre = NULL,Node *next = NULL) : n(n),pre(pre),next(next){}
    
    Node *pre ,*next;
    int n ;
    
};

Node *L::list_search(int k)
{
    Node *x = NULL;
    x = head;
    while(x != NULL && x->n != k)
    {
        x = x->next;
    }
    return x;
}


void L::list_insert(Node *x)
{
    x->next = head;
    if(head != NULL)
    {
        head->pre = x;
    }
    head = x;
}

void L::list_delete(Node *x)
{
    if(x->pre != NULL)
    {
        x->pre->next = x->next;
    }
    else
    {
        head = x->next;
    }
    if(x->next != NULL)
    {
        x->next->pre = x->pre;
    }
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
