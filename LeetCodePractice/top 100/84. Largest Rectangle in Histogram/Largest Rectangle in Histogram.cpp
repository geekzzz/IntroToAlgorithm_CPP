class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int result = 0;
		vector<int> index;
		heights.push_back(0);//注意这里要多压一个数字进heights数组里
		for (int i = 0; i < heights.size(); ++i)
		{
			while (index.size() > 0 && heights[index.back()] >= heights[i])//把height[index.back()]  >= heights[i]的数组全部删了，但是在删除前计算一遍是否为最大值
			{
				int h = heights[index.back()];
				index.pop_back();

				int width = index.size() > 0 ? index.back() : -1;//防止出错
				result = h * (i - width - 1) > result ? h * (i - width - 1) : result;
			}
			index.push_back(i);//把i压入index
		}
		return result;
	}
};