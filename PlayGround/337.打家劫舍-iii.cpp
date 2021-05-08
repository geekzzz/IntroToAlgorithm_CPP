/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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

    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        if(m.count(root) > 0)
        {
            return m[root]; 
        }
        int money = root->val;
        if(root->left)
        {
            money += helper(root->left->left) +  helper(root->left->right);
        }
        if(root->right)
        {
            money += helper(root->right->left) +  helper(root->right->right);
        }
        int money2 = helper(root->left) + helper(root->right);
        m[root] = max(money,money2);
        return max(money,money2);
    }
    unordered_map<TreeNode*,int> m;
    int rob(TreeNode* root) {
        return helper(root);
    }
};
// @lc code=end

