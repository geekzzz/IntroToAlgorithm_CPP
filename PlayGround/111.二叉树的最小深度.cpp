/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int res = INT_MAX;
    void helper(TreeNode* root,int dep)
    {
        if(!root)
        {
            return;
        }
        if(!root->left && !root->right)
        {
            res = min(res,dep);
        }
        helper(root->left,dep + 1);
        helper(root->right,dep + 1);
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        helper(root,1);
        return res;
    }
};
// @lc code=end

