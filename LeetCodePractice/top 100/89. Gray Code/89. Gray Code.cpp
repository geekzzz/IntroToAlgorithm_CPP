class Solution {
public:
    vector<int> grayCode(int n) {
        bitset<32> combine;
        vector<int> result;
        backtrack(result,n,combine);
        return result;
    }
    void backtrack(vector<int>& result,int k,bitset<32> & combine)
    {
        if(k == 0)
            result.push_back(combine.to_ulong());
        else
        {
            backtrack(result,k - 1,combine);
            combine.flip(k - 1);
            backtrack(result,k - 1,combine);
        }
    }
};
