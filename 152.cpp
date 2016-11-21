// if no positive product, the max can be negative, not 0!
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int a = 0, b = 0;
		int res = INT_MIN;
		for (auto n : nums) {
			if (n < 0) {
				int tmp = b;
				b = a ? a * n : n;
				a = tmp ? tmp * n : 0;
			}
			else {
				b = b ? b * n : 0;
				a = a ? a * n : n;
			}
			if (a) res = max(a, res);
			else res = max(b, res);
		}
		return res;
	}
};