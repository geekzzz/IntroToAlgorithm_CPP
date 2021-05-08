/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int res = 0;
    void helper(TreeNode* root,bool l)
    {
        if(!root)
            return;
        if(l && !root->left && !root->right)
        {
            res += root->val;
        }
        helper(root->left,true);
        helper(root->right,false);
    };
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        helper(root->left,true);
        helper(root->right,false);
        return res;
    }
};
// @lc code=end

