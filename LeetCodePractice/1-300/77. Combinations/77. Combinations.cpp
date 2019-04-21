class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>  res;
        vector<int> combine;
        backtrack(res,combine,n,1,k);
        return res;
    }
    void backtrack(vector<vector<int>> & res,vector<int>& combine,int n,int start,int k)
    {
        if(combine.size() == k)
        {
            res.push_back(combine);
            return;
        }
        for(int i = start;i <= n ;++i)
        {
            combine.push_back(i);
            backtrack(res,combine,n,i + 1,k);
            combine.pop_back();
        }
    }
};
