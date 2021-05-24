/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
// //////solution 1 bfs///////////////
// class Solution {
// public:
// struct nn{
//     long long  p = 0;
//     TreeNode* t = nullptr;
//     nn(long long pp, TreeNode* tt) {p = pp; t = tt;};
// };
// 	int widthOfBinaryTree(TreeNode* root) {
// 		queue<nn*> q;
// 		q.push(new nn(0,root));
// 		long long res = INT_MIN;
//         long long l = 0;
// 		while (!q.empty())
// 		{
//             int size = q.size();
//             for(int i  = 0; i < size;++i)
//             {
//                 auto nod = q.front();
// 			    q.pop();
//                 if(i == 0)
//                 {
//                     l = nod->p;
//                 }
//                 nod->p -= l;//avoid long long overflow, all minus l; 
//                 res = max(res,nod->p + 1);
//                 if(nod->t->left)
//                     q.push(  new nn(nod->p * 2,nod->t->left) );
//                 if(nod->t->right)
//                     q.push(  new nn(nod->p * 2 + 1,nod->t->right) );
//             }
// 		}
// 		return res;
// 	}
// };

/////////////solution 2 dfs///////
class Solution {
public:
    unordered_map<int,long long> m;
    unsigned long long res = 0;
    int widthOfBinaryTree(TreeNode* root) {
        helper(root,0,0);
        return res;
    }
    void helper(TreeNode* root,int d,unsigned long long p)
    {
        if(!root)
            return;
        if(m.count(d) == 0)
            m[d] = p;
        res = max(res,p - m[d] + 1);
        helper(root->left,d + 1, p * 2);
        helper(root->right,d + 1, p * 2 + 1);
    }
};

// @lc code=end

