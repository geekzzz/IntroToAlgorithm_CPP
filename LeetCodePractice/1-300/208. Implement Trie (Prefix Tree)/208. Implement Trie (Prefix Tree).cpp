class Node
{
public:
	bool isWord = false;
	Node* next[26];
	Node(bool _isWord = false) : isWord(_isWord) {
		memset(next, 0, sizeof(next));//这里要分配空间，否则会在if (p->next[word[i] - 'a'] == NULL 时出现访存错误
	}
};

class Trie {
public:
	Node* root;
	/** Initialize your data structure here. */
	Trie() {
		root = new Node();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Node* p = root;
		for (int i = 0; i < word.size(); ++i)
		{
			if (p->next[word[i] - 'a'] == NULL)
			{
				p->next[word[i] - 'a'] = new Node();
			}
			p = p->next[word[i] - 'a'];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node* p = root;
		for (int i = 0; i < word.size(); ++i)
		{
			if (p->next[word[i] - 'a'] == NULL)
				return false;
			p = p->next[word[i] - 'a'];
		}
		return p->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node* p = root;
		for (int i = 0; i < prefix.size(); ++i)
		{
			if (p->next[prefix[i] - 'a'] == NULL)
				return false;
			p = p->next[prefix[i] - 'a'];
		}
		return true;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/