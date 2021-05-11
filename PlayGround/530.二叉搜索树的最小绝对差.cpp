/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

    int minres = INT_MAX;
    vector<int> v;
    void helper(TreeNode* root)
    {
        if(!root)
            return;
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    int getMinimumDifference(TreeNode* root) {

        helper(root);
        for(int i = 0;i < v.size() - 1;++i)
        {
            auto t = abs(v[i] - v[i + 1]);
            minres = min(minres, t);
        }
        return minres;
    }
};
// @lc code=end

