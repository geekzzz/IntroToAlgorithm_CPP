/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
//这种解法分配了一个stack的内存空间，还有一种只记录指针的，但是太麻烦了，暂时只用这个
class NestedIterator {
public:
	stack<NestedInteger> s;
	NestedIterator(vector<NestedInteger> &nestedList) {

		for (int i = nestedList.size() - 1; i >= 0; --i)
		{
			s.push(nestedList[i]);
		}
	}

	int next() {
		int res = s.top().getInteger();
		s.pop();
		return res;
	}

	bool hasNext() {
		while (!s.empty())
		{
			if (s.top().isInteger())
				return true;
			auto x = s.top();
			s.pop();
			for (int i = x.getList().size() - 1; i >= 0; --i)
				s.push(x.getList()[i]);
		}
		return false;
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */