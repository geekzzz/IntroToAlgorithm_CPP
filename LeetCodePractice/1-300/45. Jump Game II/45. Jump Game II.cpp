//This problem has a nice BFS structure.Let's illustrate it using the example nums = [2, 3, 1, 1, 4] in the problem statement. We are initially at position 0. Then we can move at most nums[0] steps from it. So, after one move, we may reach nums[1] = 3 or nums[2] = 1. So these nodes are reachable in 1 move. From these nodes, we can further move to nums[3] = 1 and nums[4] = 4. Now you can see that the target nums[4] = 4 is reachable in 2 moves.
//
//Putting these into codes, we keep two pointers start and end that record the current range of the starting nodes.Each time after we make a move, update start to be end + 1 and end to be the farthest index that can be reached in 1 move from the current[start, end].
//
//To get an accepted solution, it is important to handle all the edge cases.And the following codes handle all of them in a unified way without using the unclean if statements :-)
class Solution {
public:
	int jump(vector<int>& nums) {
		int end = 0, start = 0;
		int n = nums.size();
		int step = 0;
		int maxend = 0;
		while (end < n - 1)
		{
			step++;
			maxend = end + 1;
			for (int i = start; i <= end; ++i)
			{
				maxend = max(maxend, i + nums[i]);
				if (maxend >= n)
					return step;
			}
			start = end + 1;
			end = maxend;
		}
		return step;
	}
};