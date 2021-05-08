/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
            return false;
        bool l = helper(root->left,p,q);
        bool r = helper(root->right,p,q);
        if( l && r )
            res = root;
        if( (l || r) && (root == p || root == q))
        {
            res = root;
        }
        return (l || r || root == p || root == q );
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q);
        return res;
    }
};
// @lc code=end

