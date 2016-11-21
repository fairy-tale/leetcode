class Solution {
public:
	int rob(vector<int>& nums) {
		int a = 0;
		int b = 0;
		int n = nums.size();
		if (!n) return 0;
		for (int i = 0; i < n; ++i) {
			int tmp = max(a + nums[i], b);
			a = b;
			b = tmp;
		}
		return b;
	}
};