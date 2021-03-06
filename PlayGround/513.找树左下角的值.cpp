/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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

    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int first = 0;
        if(root)
        {
            first = root->val;
        }
        while(!q.empty())
        {
            int size =  q.size();
            for(int i = 0;i < size;++i)
            {
                auto nod = q.front();
                q.pop();
                if(i == 0)
                    first = nod->val;
                if(nod->left)
                    q.push(nod->left);
                if(nod->right)
                    q.push(nod->right);
            }
        }
        return first;
    }
};
// @lc code=end

