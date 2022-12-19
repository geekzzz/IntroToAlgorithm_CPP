/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
public:
    int leftbound(vector<int> arr, int target)
    {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target > arr[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            } 
        }
        if (left == arr.size()) {
            return -1;
        }
        return left;

    }

    bool helper(vector<vector<int>>& index,  string word)
    {
        int j = 0;
        int i = 0;
        for (; i < word.size(); ++i)
        {
            char c = word[i];
            if (index[c].size() == 0)
            {
                break;
            }
            int pos = leftbound(index[c], j);
            if (pos == -1)
                break;
            j = index[c][pos] + 1;
        }
        if (i == word.size())
        {
            return true;
        }
        return false;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> index(256, vector<int>(0));
        for (int i = 0; i < s.size(); ++i)
        {
            index[s[i]].push_back(i);
        }
        //注意，这里需要使用m来对string去重，否则遍历每个string会导致复杂度过高
        unordered_map<string,int> m;
        for(int j = 0;j < words.size();++j)
        {
            m[words[j]]++;
        }
        int res = 0;
        for(auto it = m.begin();it != m.end();++it)
        {
            if(helper(index,it->first))
            {
                res += it->second;
            }
        }
        return res;
    }
};
// @lc code=end

