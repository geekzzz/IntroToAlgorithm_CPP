/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    struct Node{
        TreeNode* n;
        int d;
        Node(TreeNode* nod,int dep) : n(nod),d(dep) {}
    };

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* t = new TreeNode(val);
            t->left = root;
            return t;
        }
        queue<Node*> q;
        int curdep = 1;
        q.push(new Node(root,1));
        while(!q.empty())
        {
            auto nod = q.front();
            q.pop();
            if(nod->d == depth - 1)
            {
                auto l = nod->n->left;
                auto r = nod->n->right;
                nod->n->left = new TreeNode(val);
                nod->n->left->left = l;
                nod->n->right = new TreeNode(val);
                nod->n->right->right = r;
            }
            else 
            {
                if(nod->n->left)
                    q.push(new Node(nod->n->left,nod->d + 1));
                if(nod->n->right)
                    q.push(new Node(nod->n->right,nod->d + 1));
            }
        }
        return root;
    }
};
// @lc code=end

