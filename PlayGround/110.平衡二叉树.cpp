/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool flag = true;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        if(abs(l - r) > 1)
        {
            flag = false;
        }
        return max(l + 1,r + 1);
    }
    bool isBalanced(TreeNode* root) {
        helper(root);
        return flag;
    }
};
// @lc code=end

