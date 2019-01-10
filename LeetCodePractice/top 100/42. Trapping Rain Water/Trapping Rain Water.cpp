
//�ⷨһ
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (!n)
			return 0;
		vector<int> maxleft(n), maxright(n);
		int result = 0;
		maxleft[0] = height[0];
		for (int i = 1; i < n; i++)//��ǰ����ɨ�裬�õ�ÿ��iλ�ö�Ӧ�������ߵ�λ��
		{
			maxleft[i] = max(height[i], maxleft[i - 1]);
		}
		maxright[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; i--)//�Ӻ���ǰɨ�裬�õ�ÿ��iλ�ö�Ӧ���ұ���ߵ�λ��
		{
			maxright[i] = max(height[i], maxright[i + 1]);
		}
		for (int i = 1; i < n - 1; ++i)
		{
			result += min(maxleft[i], maxright[i]) - height[i];//�����������ߵ���Сֵ����ȥ��ǰ�õ�i��ĸ߶�ֵ���õ��õ�i�����ˮֵ
		}
		return result;
	}
};

//�ⷨ��
//Here is my idea : instead of calculating area by height*width, we can think it in a cumulative way.In other words, sum water amount of each bin(width = 1).
//Search from left to right and maintain a max height of left and right separately, which is like a one - side wall of partial container.Fix the higher one and flow water from the lower part.For example, if current height of left is lower, we fill water in the left bin.Until left meets right, we filled the whole container.
class Solution {
public:
	int trap(int A[], int n) {
		int left = 0; int right = n - 1;
		int res = 0;
		int maxleft = 0, maxright = 0;
		while (left <= right) {
			if (A[left] <= A[right]) {
				if (A[left] >= maxleft) maxleft = A[left];
				else res += maxleft - A[left];
				left++;
			}
			else {
				if (A[right] >= maxright) maxright = A[right];
				else res += maxright - A[right];
				right--;
			}
		}
		return res;
	}
};