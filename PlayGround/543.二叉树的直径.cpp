/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int maxres = INT_MIN;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = helper(root->left);
        int r = helper(root->r);
        maxres = max(maxres,l + r + 1);
        return max(l + 1,r + 1 );
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return maxres;
    }
};
// @lc code=end

