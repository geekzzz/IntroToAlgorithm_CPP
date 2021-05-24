/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
        unordered_map<string, int> m;
        vector<TreeNode*> res;
        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            helper(root);
            return res;
        }
        string helper(TreeNode* root)
        {
            if (!root)
                return "";
            string subtree = to_string(root->val) + " " + helper(root->left) + " " + helper(root->right);
            if (m[subtree] == 1)
            {
                res.push_back(root);
            }
            m[subtree]++;
            return subtree;
        }
};
// @lc code=end

