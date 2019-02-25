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
		if (!root)
			return "#";
		return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
	}
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		return mydeserialize(data);
	}
	TreeNode* mydeserialize(string& data) {//ע������data������
		if (data[0] == '#')
		{
			if (data.size() > 1)
				data = data.substr(2);
			return nullptr;
		}
		TreeNode* root = new TreeNode(helper(data));
		root->left = mydeserialize(data);
		root->right = mydeserialize(data);
		return root;
	}


	int helper(string& data)//ע������data������
	{
		int pos = data.find(',');
		int result = stoi(data.substr(0, pos));
		data = data.substr(pos + 1);//ע��substr�÷��������ǽ�ȡ��pos+1λ�ÿ�ʼ�ĺ������е��ַ�����data
		return result;
	}

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));