/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    vector<int> res;
    void helper(TreeNode* root)
    {
        if(!root )
            return;
        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        for(int i = 0;i < res.size() - 1;++i)
        {
            if(res[i] >= res[i + 1])
            {
                return false;
            }
        }
        return true;
    }

// bool isValidBST(TreeNode* root) {
//         if (!root) return true;
//         vector<int> vals;
//         inorder(root, vals);
//         for (int i = 0; i < vals.size() - 1; ++i) {
//             if (vals[i] >= vals[i + 1]) return false;
//         }
//         return true;
//     }
//     void inorder(TreeNode* root, vector<int>& vals) {
//         if (!root) return;
//         inorder(root->left, vals);
//         vals.push_back(root->val);
//         inorder(root->right, vals);
//     }

};
// @lc code=end

