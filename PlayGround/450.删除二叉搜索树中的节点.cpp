/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* successor(TreeNode* root)
    {
        auto cur = root->right;
        while(cur->left)
            cur = cur->left;
        return cur;
    }
    TreeNode* predeccessor(TreeNode* root)
    {
        auto cur = root->left;
        while(cur->right)
            cur = cur->right;
        return cur;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val > key)
            root->left = deleteNode(root->left,key);
        else if(root->val < key)
            root->right = deleteNode(root->right,key);
        else 
        {
            if(!root->left && !root->right)
            {
                delete root;
                root = nullptr;
            }
            else if(root->left)
            {
                root->val = predeccessor(root)->val;
                root->left = deleteNode(root->left,root->val);
                
            }
            else if(root->right)
            {
                root->val = successor(root)->val;
                root->right = deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};
// @lc code=end

