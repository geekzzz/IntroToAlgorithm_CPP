/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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

    //////// moris zhong xu jie fa///////////////
    int base, count, maxCount;
    vector<int> answer;

    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            answer = vector<int> {base};
        }
    }

    vector<int> findMode(TreeNode* root) {
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            if (!cur->left) {
                update(cur->val);
                cur = cur->right;
                continue;
            }
            pre = cur->left;
            while (pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                update(cur->val);
                cur = cur->right;
            }
        }
        return answer;
    }

    //////////zhong xu jie fa ///////////////
    // int nownum;
    // int nowcount;
    // int maxcount = INT_MIN;
    // vector<int> res;
    // void helper(TreeNode* root)
    // {
    //     if(!root)
    //         return;
    //     helper(root->left);
    //     if(root->val == nownum)
    //     {
    //         nowcount++;
    //     }
    //     else
    //     {
    //         nowcount = 1;
    //         nownum = root->val;
    //     }
    //     if(nowcount == maxcount)
    //         {
    //             res.push_back(root->val);
    //         }
    //         else if(nowcount > maxcount)
    //         {
    //             maxcount = nowcount;
    //             res.clear();
    //             res.push_back(root->val);
    //         }
    //     helper(root->right);
    // }
    // vector<int> findMode(TreeNode* root) {
    //     helper(root);
    //     return res;
    // }




    ///// ji ben jie fa ///////
    // unordered_map<int,int> m;
    // int maxres = 0;
    // void helper(TreeNode* root)
    // {
    //     if(!root)
    //         return;
    //     m[root->val]++;
    //     maxres = max(maxres,m[root->val]);
    //     helper(root->left);
    //     helper(root->right);
    // }

    // vector<int> findMode(TreeNode* root) {
    //     helper(root);
    //     vector<int> res;
    //     for(auto it = m.begin();it != m.end();++it)
    //     {
    //         if(it->second == maxres)
    //         {
    //             res.push_back(it->first);
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end

