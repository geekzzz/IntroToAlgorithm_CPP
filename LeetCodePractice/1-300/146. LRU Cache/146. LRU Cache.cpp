class LRUCache {
public:
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		if (kv.find(key) == kv.end())//if(kv.count(key) == 0)
			return -1;
		updateLRU(key);
		return kv[key];
	}

	void put(int key, int value) {
		if (kv.size() == size && kv.find(key) == kv.end())
			evict();
		updateLRU(key);
		kv[key] = value;
	}

	void updateLRU(int key)
	{
		if (kv.find(key) != kv.end())
			LRU.erase(mp[key]);
		LRU.push_front(key);
		mp[key] = LRU.begin();
	}

	void evict()
	{
		mp.erase(LRU.back());
		kv.erase(LRU.back());
		LRU.pop_back();
	}



	int size;
	list<int> LRU;//lru list;
	unordered_map<int, int> kv; // key->value;
	unordered_map<int, list<int>::iterator> mp;//Key-> List it

};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/