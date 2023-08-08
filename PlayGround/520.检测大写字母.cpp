/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int lowLastIdx = -1;
        int upLastIdx = -1;
        for(int i = 0; i < word.size();++i)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
                lowLastIdx = i;
            else
                upLastIdx = i;
        }
        if(upLastIdx == -1)
            return true;
        if(lowLastIdx == -1)
            return true;
        if(lowLastIdx  > -1 && upLastIdx <= 0)
            return true;
        return false;
    }
};
// @lc code=end

