/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        return build(nums,0,nums.size() - 1);
    }
    TreeNode* build(vector<int>& nums,int l,int r)
    {
        if(l > r)
        {
            return nullptr;
        }
        int cur = l;
        for(int i = l;i <= r;++i)
        {
            if(nums[i] > nums[cur])
            {
                cur = i;
            }
        }
        TreeNode* t = new TreeNode(nums[cur]);
        t->left = build(nums,l,cur - 1 );
        t->right = build(nums,cur + 1, r);
        return t;
    }
};
// @lc code=end

