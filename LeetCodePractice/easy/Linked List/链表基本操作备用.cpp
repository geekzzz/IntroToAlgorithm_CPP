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
//注意这个操作删除最后一个节点会引起倒数第二个节点野指针
void deleteNode(ListNode* node) {

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
	while (p->next != NULL)
	{
		cout << p->val << "->";
		p = p->next;
	}
	cout << p->val << endl;
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
}

void deleteNode(ListNode* node);

int main()
{
	ListNode *head = new ListNode(1000);
	for (int i = 0; i < 10; ++i)
	{
		addNode(head, i);
	}
	auto x = findNode(head, -1);
	cout << x->val << "ffff" << endl;
	printList(head);
	deleteNode(findNode(head, 8));
	printList(head);

	system("pause");
	return 0;
}

