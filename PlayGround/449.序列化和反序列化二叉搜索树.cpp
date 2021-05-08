/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "X,";
        string l = serialize(root->left);
        string r = serialize(root->right);
        return to_string(root->val) + "," + l + r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }

    vector<string> split(strign s, string c)
    {
        int lastpos = s.find_first_not_of(c,0);
        int pos = s.find_first_of(c,lastpos);
        while(lastpos != string::npos || pos != string::npos)
        {
            
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

