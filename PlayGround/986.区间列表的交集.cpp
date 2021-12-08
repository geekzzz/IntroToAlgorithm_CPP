/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        while(i < firstList.size() && j < secondList.size())
        {
            if(firstList[i][1] < secondList[j][0])
            {
                i++;
            }
            else if(secondList[j][1] < firstList[i][0])
            {
                j++;
            }
            else 
            {
                vector<int> r;
                r.push_back(max(firstList[i][0],secondList[j][0]));
                r.push_back(min(firstList[i][1],secondList[j][1]));
                res.push_back(r);
                if(firstList[i][1] > secondList[j][1])
                {
                    ++j;
                }
                else if(firstList[i][1] < secondList[j][1])
                {
                    ++i;
                }
                else
                {
                    i++;
                    j++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

