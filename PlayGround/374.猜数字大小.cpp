/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
         int r = n;
         while(l <= r)
         {
            int m = l + (r - l)/2;
            if( guess(m) > 0)
            {
               l = m + 1;
            }
            else if(guess(m) < 0)
            {
               r = m - 1;
            }
            else
            {
               return m;
            }
         }
         return l;
    }
};
// @lc code=end

