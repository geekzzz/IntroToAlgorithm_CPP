/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
        list<string> s = split(data,",");
        TreeNode* t = build(s);
        return t;
    }

    TreeNode* build(list<string>& res)
    {
        string s = res.front();
        res.pop_front();
        if(s == "X")
            return nullptr;
        TreeNode* tree = new TreeNode();
        tree->val = stoi(s);
        tree->left = build(res);
        tree->right = build(res);
        return tree;
    }

    list<string> split(string s, string c)
    {
        list<string> res;
        auto lastpos = s.find_first_not_of(c,0);
        auto pos = s.find_first_of(c,lastpos);
        while(lastpos != string::npos || pos !=  string::npos  )
        {
            res.push_back(s.substr(lastpos, pos - lastpos));
            lastpos = s.find_first_not_of(c,pos);
            pos = s.find_first_of(c,lastpos);
        }
        return res;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

