/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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


 // Recursive solution
// class Solution {
// public: 
//     int numberofpaths(TreeNode* root, int leftnum)
//     {
//         if(!root)
//             return 0;
//         leftnum -= root->val;
//         return (leftnum == 0 ? 1 : 0 ) + numberofpaths(root->left,leftnum) + numberofpaths(root->right,leftnum);
//     }
//     int pathSum(TreeNode* root, int targetSum) {
//         if(!root)
//             return 0;
//         return numberofpaths(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
//     }
// };

//prefix sum solution
class Solution {
public: 
    unordered_map<int,int> m;
    int res = 0;
    void Recur(TreeNode* root, int targetSum, int nowsum)
    {
        if(!root)
            return;
        nowsum += root->val;
        res += m[nowsum -targetSum ];
        m[nowsum]++;
        Recur(root->left,targetSum,nowsum);
        Recur(root->right,targetSum,nowsum);
        m[nowsum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        m[0] = 1;
        Recur(root,targetSum,0);
        return res;
    }
};

// @lc code=end

