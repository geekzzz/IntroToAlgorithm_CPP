/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int resnum;
    int maxtime = 1;
    void helper(TreeNode* root, int pre,int times)
    {
        if(!root)
        {
            return;
        }
        if(root->val == pre)
        {
            times++;
            maxtime = max(maxtime,times);
            
        }
    }
    vector<int> findMode(TreeNode* root) {

    }
};
// @lc code=end

