/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<vector<int>> res;
    void helper(TreeNode* root,vector<int> s)
    {
        s.push_back(root->val);
        if(!root->left && !root->right)
        {
            res.push_back(s);
        }
        if(root->left)
            helper(root->left,s);
        if(root->right)
            helper(root->right,s);
            
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root)
            helper(root,vector<int>());
        vector<string> rrr;
        for(int i = 0;i < res.size();++i)
        {
            int size = res[i].size();
            if(size > 0)
            {
                string rr;
                for(int j  = 0;j < size;++j)
                {
                    if(j == 0)
                    {
                        rr += std::to_string(res[i][j]);
                    }
                    else 
                    {
                        rr += "->";
                        rr += std::to_string(res[i][j]);
                    }
                }
                rrr.push_back(rr);
            }
            
        }
        return rrr;
    }
};
// @lc code=end

