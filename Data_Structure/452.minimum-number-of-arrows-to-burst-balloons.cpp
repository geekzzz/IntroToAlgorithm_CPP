/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */
class Solution {
bool cmp(const vector<int> & a,const vector<int> & b)
{
    return a[0] < b[0];
}

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int cur = 0;
        for(int i = 1;i < points.size();++i)
        {
            
        }  
    }
};

