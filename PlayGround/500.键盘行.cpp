/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
        set<char> row2{'a','s','d','f','g','h','j','k','l'};
        set<char> row3{'z','x','c','v','b','n','m'};
        for(int i = 0;i < words.size();++i)
        {
            set<char> cur;
            if(row1.find(tolower(words[i][0]) ) != row1.end())
            {
                cur = row1;
            }
            else if(row2.find(tolower(words[i][0])) != row2.end())
            {
                cur = row2;
            }
            else
            {
                cur = row3;
            }
            bool valid = true;
            for(int j = 1;j < words[i].size();++j)
            {
                if(cur.find(tolower(words[i][j])) == cur.end())
                {
                    valid = false;
                    break;
                }
            }
            if(valid)
                res.push_back(words[i]);
        }
        return res;
    }
};
// @lc code=end

