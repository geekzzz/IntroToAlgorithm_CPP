//Reverse Polish Notation��һ�ֱ�ʾ����ķ�������ջ��������в���
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
					st.push(b - a);//ע����b-a
					break;
				case '*':
					st.push(a * b);
					break;
				case '/':
					st.push(b / a);//ע����b/a
					break;
				}
			}
		}
		return st.top();
	}
};