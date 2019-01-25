class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int result = 0;
		vector<int> index;
		heights.push_back(0);//ע������Ҫ��ѹһ�����ֽ�heights������
		for (int i = 0; i < heights.size(); ++i)
		{
			while (index.size() > 0 && heights[index.back()] >= heights[i])//��height[index.back()]  >= heights[i]������ȫ��ɾ�ˣ�������ɾ��ǰ����һ���Ƿ�Ϊ���ֵ
			{
				int h = heights[index.back()];
				index.pop_back();

				int width = index.size() > 0 ? index.back() : -1;//��ֹ����
				result = h * (i - width - 1) > result ? h * (i - width - 1) : result;
			}
			index.push_back(i);//��iѹ��index
		}
		return result;
	}
};