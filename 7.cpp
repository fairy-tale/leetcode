//only int
class Solution {
public:
	int reverse(int x) {
		if (x == INT_MIN) return 0;
		int t = abs(x);
		int ans = 0;
		while (t) {
			if (INT_MAX / 10 < ans || (INT_MAX / 10 == ans && INT_MAX % 10 < t % 10)) return 0;
			ans *= 10;
			ans += t % 10;
			t /= 10;
		}
		return x > 0 ? ans : -ans;
	}
};

//use long
class Solution {
public:
	int reverse(int x) {
		long x1 = x;
		long tmp = 0;
		while (x1) {
			tmp *= 10;
			tmp += x1 % 10;
			x1 /= 10;
		}
		if (tmp > INT_MAX || tmp < INT_MIN) return 0;
		int ans = tmp;
		return ans;
	}
};