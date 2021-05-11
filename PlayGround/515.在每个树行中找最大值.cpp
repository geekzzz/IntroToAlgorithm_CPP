/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return vector<int> {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty())
        {
            int size =  q.size();
            int maxres = INT_MIN;
            for(int i = 0;i < size;++i)
            {
                auto nod = q.front();
                q.pop();
                maxres = max(maxres,nod->val);
                
                if(nod->left)
                    q.push(nod->left);
                if(nod->right)
                    q.push(nod->right);
            }
            res.push_back(maxres);
        }
        return res;
    }
};
// @lc code=end

