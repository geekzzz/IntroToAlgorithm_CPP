//用一个unordered_set来做
class RandomizedSet {
public:
	/** Initialize your data structure here. */
	unordered_set<int> s;
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (s.find(val) != s.end())
			return false;
		s.insert(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (s.find(val) == s.end())
		{
			return false;
		}
		s.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int n = s.size();
		int count = 0;
		int random = rand() % n;
		for (auto x : s)
		{
			if (count == random)
				return x;
			count++;

		}
		return *s.begin();
	}
};