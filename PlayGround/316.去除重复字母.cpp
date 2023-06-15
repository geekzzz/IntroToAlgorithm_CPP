/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<int> st;
         unordered_map<char, int> count;
         unordered_map<char, bool> seen;
         for(int i = 0; i < s.size(); ++i)
         {
            count[s[i]]++;
         }
         for(int i = 0;i < s.size();++i)
         {
            count[s[i]]--;
            if(seen[s[i]])
               continue;
            while(!st.empty() && st.top() > s[i] && count[st.top()] > 0)
            {
               seen[st.top()] = false;
               st.pop();
            }
            seen[s[i]] = true;
            st.push(s[i]);
         }
         string res;
         while(!st.empty())
         {
            res.push_back(st.top());
            st.pop();
         }
         reverse(res.begin(), res.end());
         return res;
    }
};
// @lc code=end

