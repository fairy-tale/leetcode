class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = INT_MIN;
		int cur = 0;
		for (auto &n : nums) {
			if (cur + n < 0) {
				cur = 0;
			}
			else {
				cur += n;
				sum = max(sum, cur);
			}
		}
		if (sum == INT_MIN) {
			for (auto &n : nums)
				sum = max(sum, n);
		}
		return sum;
	}
};