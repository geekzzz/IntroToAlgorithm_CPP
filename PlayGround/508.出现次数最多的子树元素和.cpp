/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    unordered_map<int,int> m;
    int maxres = INT_MIN;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        int sum = root->val + helper(root->left) + helper(root->right);
        m[sum]++;
        maxres = max(maxres,m[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        vector<int> res;
        for(auto it = m.begin();it != m.end();++it)
        {
            if(it->second == maxres)
            {
                res.push_back(it->first);
            }
        }
        return res;
    }
};
// @lc code=end

