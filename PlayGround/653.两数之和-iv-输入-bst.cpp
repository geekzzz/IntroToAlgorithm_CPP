/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
 ////solution 1//////////
// class Solution {
// public:
//     unordered_map<int,int> m;
//     bool find = false;
//     void helper(TreeNode* root,int k)
//     {
//         if(!root || find)
//             return;
//         if(m[k - root->val] > 0)
//         {
//             find = true;
//             return;
//         }
//         m[root->val]++;
//         helper(root->left,k);
//         helper(root->right,k);
//     }
//     bool findTarget(TreeNode* root, int k) {
//         helper(root,k);
//         return find;
//     }
// };



//////////////////solution 2/////////
class Solution {
public:
    vector<int> in;

    bool findTarget(TreeNode* root, int k) {
        helper(root);
        int left = 0, right = in.size() - 1;
        while (left < right)
        {
            int sum = in[left] + in[right];
            if (sum > k)
            {
                right--;
            }
            else if (sum < k)
            {
                left++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    void helper(TreeNode* root) {
        if (!root)
            return;
        helper(root->left);
        in.push_back(root->val);
        helper(root->right);
    }
};
// @lc code=end

