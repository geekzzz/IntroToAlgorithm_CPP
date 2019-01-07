
//传统使用z栈的解法
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        stack<char> ss;
        for(int i = 0;i < s.size();++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                ss.push(s[i]);
            else if(ss.empty() || m[ss.top()] != s[i])//注意这行!!!!!!!!!!!!
                return false;
            else
                ss.pop();
        }
        return ss.empty();
    }
};
