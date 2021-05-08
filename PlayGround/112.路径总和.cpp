/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool flag = false;
    void helper(TreeNode* root,int sum,int t)
    {
        if(!root)
        return;
        sum += root->val;
        if(!root->left && !root->right &&  sum == t)
        {
            flag = true;
        }
        helper(root->left,sum,t);
        helper(root->right,sum,t);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        helper(root,0,targetSum);
        return flag;
    }
};
// @lc code=end

