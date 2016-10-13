// change dividend and divisor into negative one (instead of using abs()) this could avoid the overflow by INT_MIN
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
		int res = 0;
		bool neg = false;
		if (divisor > 0) {
			divisor = -divisor;
			neg = !neg;
		}
		if (dividend > 0) {
			dividend = -dividend;
			neg = !neg;
		}
		int k = divisor;
		int tmp = 1;
		while (k >= (INT_MIN >> 1) && (k << 1) >= dividend) {
			k <<= 1;
			tmp <<= 1;
		}
		for (; dividend < 0 && tmp; tmp >>= 1, k >>= 1) {
			if (dividend <= k) {
				res += tmp;
				dividend -= k;
			}
		}
		return neg ? -res : res;
	}
};