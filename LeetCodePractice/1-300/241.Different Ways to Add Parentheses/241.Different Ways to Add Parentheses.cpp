class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i = 0;i < input.size();++i)
        {
            char c = input[i];
            if(c == '+' || c == '-' || c == '*')
            {
                vector<int> le = diffWaysToCompute(input.substr(0,i)) ;
                vector<int> ri =  diffWaysToCompute(input.substr(i + 1)) ;
                for(auto l : le)
                {
                    for(auto r: ri)
                    {
                        if(c == '+')
                            res.push_back(l + r);
                        else if(c == '-')
                            res.push_back(l - r);
                        else if(c == '*')
                            res.push_back(l * r);
                    }
                }
            }
        }
        if(!res.size())
            res.push_back(stoi(input));
        return res;
    }
};
