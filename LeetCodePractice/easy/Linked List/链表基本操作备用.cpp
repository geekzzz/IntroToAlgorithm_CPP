#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


void deleteNode(ListNode* node);
void addNode(ListNode *head, int val);
void printList(ListNode* head);
ListNode* findNode(ListNode* head, int val);
ListNode* ReverseList(ListNode* head);

//注意这个操作删除最后一个节点会引起倒数第二个节点野指针
void deleteNode(ListNode* node)
{

	if (node->next == NULL)
	{
		delete node;
	}
	else
	{
		ListNode* next = node->next;
		*node = *next;
		delete next;
	}
}

void addNode(ListNode *head, int val)
{
	auto p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	ListNode *n = new ListNode(val);
	p->next = n;
}

void printList(ListNode* head)
{
	auto p = head;
	while (p)
	{
		cout << p->val << "->";
		p = p->next;
	}
	cout << endl;
}

ListNode* findNode(ListNode* head, int val)
{
	auto p = head;
	while (p->next != NULL)
	{
		if (p->val == val)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}
ListNode* ReverseList(ListNode* head)
{
	ListNode* pre = NULL;
	ListNode* next = NULL;
	while (head)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

bool hasCycle(ListNode *head) {
	if (head == NULL)
		return false;
	auto p = head->next;
	while (p)
	{
		if (p == head)
			return true;
		p = p->next;
	}
	return false;
}

int main()
{
	ListNode *head = new ListNode(1);
	for (int i = 2; i < 6; ++i)
	{
		addNode(head, i);
	}
	//findNode(head, 5)->next = head;
	//printList(head);
	head = NULL;
	cout << hasCycle(head);
	//printList(reverseList(head));
	system("pause");
	return 0;
}


