//Reverse Polish Notation是一种表示计算的方法，用栈来对其进行操作
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		int a, b;
		for (int i = 0; i < tokens.size(); ++i)
		{
			string s = tokens[i];
			if (s.size() > 1 || isdigit(s[0]))
				st.push(stoi(s));
			else
			{
				a = st.top();
				st.pop();
				b = st.top();
				st.pop();
				switch (s[0])
				{
				case '+':
					st.push(a + b);
					break;
				case '-':
					st.push(b - a);//注意是b-a
					break;
				case '*':
					st.push(a * b);
					break;
				case '/':
					st.push(b / a);//注意是b/a
					break;
				}
			}
		}
		return st.top();
	}
};