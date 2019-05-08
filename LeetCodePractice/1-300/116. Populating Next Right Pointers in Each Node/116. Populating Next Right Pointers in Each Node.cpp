/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() {}

Node(int _val, Node* _left, Node* _right, Node* _next) {

val = _val;
left = _left;
right = _right;
next = _next;
}
};
*/
class Solution {
public:
	Node* connect(Node* root) {
		if (!root)
			return root;
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i < n; ++i)
			{
				Node* tmp = q.front();
				q.pop();
				if (!q.empty())
				{
					Node* t = q.front();
					tmp->next = t;
				}
				else
					tmp->next = NULL;
				if (i == n - 1)
				{
					tmp->next = NULL;
				}
				if (tmp->left)
					q.push(tmp->left);
				if (tmp->right)
					q.push(tmp->right);
			}
		}
		return root;

	}
};