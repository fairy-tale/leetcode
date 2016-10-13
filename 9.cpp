class Solution {
public:
	bool isPalindrome(int x) {
		int t = x, tmp = x;
		int k = 0;
		if (x < 0) return false;
		while (tmp) {
			tmp /= 10;
			k++;
		}
		int k1 = pow(10, k - 1);
		while (x) {
			if (x % 10 != t / k1) return false;
			x /= 10;
			t %= k1;
			k1 /= 10;
		}
		return true;
	}
};