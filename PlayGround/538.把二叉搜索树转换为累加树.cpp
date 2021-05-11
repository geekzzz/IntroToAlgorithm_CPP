/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    void helper(TreeNode* root,int &last)
    {
        if(!root)
            return;
        helper(root->right,last);
        last += root->val;
        root->val = last;
        helper(root->left,last);
    }
    TreeNode* convertBST(TreeNode* root) {
        int n = 0;
        helper(root,n);
        return root;
    }
};
// @lc code=end

