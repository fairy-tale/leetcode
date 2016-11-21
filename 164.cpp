//bucket sort.
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return 0;
		int min_n = *min_element(nums.begin(), nums.end());
		int max_n = *max_element(nums.begin(), nums.end());
		//if don't add n - 2, the test case like [1,1,1,1,1,5,5,5,5,5,5] can't pass. Since the step = 0!
		int step = (max_n - min_n + n - 2) / (n - 1);
		//step = 0 means all the num are equal.
		if (!step) return 0;
		int m = ((max_n - min_n) / step) + 1;
		int res = INT_MIN, last_upper = INT_MIN;
		vector<int> a(m, INT_MAX);
		vector<int> b(m, INT_MIN);
		for (auto num : nums) {
			int k = (num - min_n) / step;
			a[k] = min(a[k], num);
			b[k] = max(b[k], num);
		}
		for (int i = 0; i < m; ++i) {
			if (a[i] <= b[i]) {
				if (last_upper != INT_MIN) res = max(res, a[i] - last_upper);
				last_upper = b[i];
			}
		}
		return res;
	}
};