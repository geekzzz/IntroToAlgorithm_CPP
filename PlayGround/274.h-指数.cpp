/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         vector<int> h(5001, 0);
//         for (int i = 0; i < citations.size(); ++i)
//         {
//             for (int j = 0; j <= citations[i]; ++j)
//             {
//                 h[j]++;
//             }
//         }
//         for (int i = h.size() - 1; i >= 0; --i)
//         {
//             if (h[i] >= i)
//             {
//                 return i;
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); ++i)
        {
            if (citations[i] <= i)
            {
                return i;
            }
        }
        return citations.size();
    }
};
// @lc code=end

