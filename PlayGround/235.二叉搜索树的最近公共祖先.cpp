/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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

// class Solution {
// public:
//     TreeNode* res = nullptr;
//     bool find = false;
//     unordered_set<TreeNode*> helper(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
//         unordered_set<TreeNode*> t;
//         if(find)
//             return t;
//         if(!root)
//             return t;
//         t.insert(root);
        
//         t.merge(helper(root->left,p,q));
//         t.merge(helper(root->right,p,q));
//         if(t.count(p) && t.count(q) && !find)
//         {
//             find = true;
//             res = root;
//         }
//         return t;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         helper(root,p,q);
//         return res;
//     }
// };

class Solution {
public:


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = root;
        while(true)
        {
            if(p->val < res->val && q->val < res->val)
            {
                res = res->left;
            }
            else if (p->val > res->val && q->val > res->val)
            {
                res = res->right;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

