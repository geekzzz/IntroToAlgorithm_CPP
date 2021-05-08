/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> t;
            for(int i = 0;i < size ;++i)
            {
                TreeNode* nod = q.front();
                q.pop();
                t.push_back(nod->val);
                if(nod->left)
                    q.push(nod->left);
                if(nod->right)
                    q.push(nod->right);
            }
            if(flag)
            {
                reverse(t.begin(),t.end());
            }
            res.push_back(t);
            flag = !flag;
        }
        return res;
    }
};
// @lc code=end

