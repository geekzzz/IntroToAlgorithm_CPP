class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> dp(s.size(), 0);
		int max = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ')')//���s[i] == '(',�򲻺Ϸ����������������
			{
				if (s[i - 1] == '(')//���s[i - 1] == '(',��ֻ��Ҫ��dp[i - 2] �ĳ����ϼ�2����
				{
					dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;//��Ԫ�������ֹ�������Խ��
					if (dp[i] > max)
						max = dp[i];
				}

				else//s[i - 1] == ')'�����������Ҫ����ǰ����ַ�����
				{
					if (s[i - 1 - dp[i - 1]] == '(')// i - 1 Ϊǰ��')'�ŵ�λ�ã�dp[i - 1] Ϊi - 1λ�õ���Ӵ���λ�ã��� i - 1 - dp[i - 1]��ʾǰ�����Ӵ�֮ǰ��һ���ַ���λ�ã����Ϊ'(',����Ժ͵�ǰiλ�õ�')'ƥ�䡣
					{
						/*
						
						��Ϊ�����ֿ���ͨ��ǰ��������Ѿ�ȷ������һ���Ϸ����Ӵ���dp[i - 1] + 2 ��ʾ��ǰ')'ƥ�䵽��'('���Ӵ����ȣ�
						����ǰ����ܻ��п��ܳ����Ӵ�������()(())����£�i = 5��ʱ��ƥ�䵽��2λ�������ţ�����ǰ�滹��()Ҳ�ǺϷ��ģ�����Ҫ�����������
						��ȡ������ȵķ���Ϊ�����ȼ����±꣺i - 1 - dp[i - 1],Ȼ���� - 1 �͵õ���ǰ��ĺϷ��Ӵ����±꣬Ȼ�����ȡ�����ȣ�Ҳ�п���Ϊ0����Ȼ����ӾͿ��ԡ�
						ͬ����Ҳ�п���Խ�磬��������Ԫ���������Խ�������
						*/
						dp[i] = dp[i - 1] + 2 + ((i - 1 - dp[i - 1] - 1) >= 0 ? dp[i - 1 - dp[i - 1] - 1] : 0);
						if (dp[i] > max)
							max = dp[i];
					}
				}
			}
		}
		return max;
	}
};