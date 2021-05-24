/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
    int geth(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(geth(root->left),geth(root->right)) + 1;
    }
    int getw(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(getw(root->left),getw(root->right)) * 2 + 1;
    }
    void helper(TreeNode* root,int h,int l,int r,vector<vector<string>> & res)
    {
        if(!root)
            return;
        if(l > r)
            return;
        int m = (l + r)/2;
        res[h][m] = to_string(root->val) ;
        helper(root->left,h + 1, l,m - 1,res);
        helper(root->right,h + 1,m + 1,r,res);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        
        int h = geth(root);
        int w = getw(root);
        vector<vector<string>> res(h,vector<string>(w,""));
        helper(root,0,0,w - 1,res);
        return res;
    }
};
// @lc code=end

