// n could be INT_MIN
class Solution {
public:
	double myPow(double x, int n) {
		double res = 1;
		long n1 = n;
		if (n1 < 0) {
			x = 1 / x;
			n1 = -n1;
		}
		while (n1) {
			res *= n1 & 1 ? x : 1;
			n1 >>= 1;
			x *= x;
		}
		return res;
	}
};