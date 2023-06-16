/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26,0);
        for(int i = 0;i < magazine.size();++i)
        {
            m[magazine[i] - 'a']++;
        }
        for(int i = 0;i < ransomNote.size();++i)
        {
            m[ransomNote[i] - 'a']--;
            if(m[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

