//思想:https://www.cnblogs.com/grandyang/p/4431646.html
//[5, 7]里共有三个数字，分别写出它们的二进制为：
//
//101　　110　　111
//
//相与后的结果为100，仔细观察我们可以得出，最后的数是该数字范围内所有的数的左边共同的部分，如果上面那个例子不太明显，我们再来看一个范围[26, 30]，它们的二进制如下：
//
//11010　　11011　　11100　　11101　　11110
//
//发现了规律后，我们只要写代码找到左边公共的部分即可，我们可以从建立一个32位都是1的mask，然后每次向左移一位，比较m和n是否相同，不同再继续左移一位，直至相同，然后把m和mask相与就是最终结果，代码如下：


class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int d = INT_MAX;
		while ((m & d) != (n & d)) {
			d <<= 1;
		}
		return m & d;
	}
};

//// 
//
//此题还有另一种解法，不需要用mask，直接平移m和n，每次向右移一位，直到m和n相等，记录下所有平移的次数i，然后再把m左移i位即为最终结果，代码如下：

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int i = 0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			++i;
		}
		return (m << i);
	}
};