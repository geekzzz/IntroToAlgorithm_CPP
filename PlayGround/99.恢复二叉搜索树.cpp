/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    vector<TreeNode*> l;
    vector<int> v;
        
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        l.push_back(root);
        v.push_back(root->val);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(v.begin(),v.end(),less<int>());
        for(int i = 0;i < v.size();++i)
        {
            l[i]->val = v[i];
        }
    }
};
// @lc code=end

