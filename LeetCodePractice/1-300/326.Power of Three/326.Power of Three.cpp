class Solution {
public:
	bool isPowerOfThree(int n) {
		return n > 0 && (int(log10(n) / log10(3)) - log10(n) / log10(3)) == 0;
	}
};