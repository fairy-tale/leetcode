class Solution {
public:
	int rob(vector<int>& nums) {
		int a1 = 0, b1 = 0;
		int a2 = 0, b2 = 0;
		int n = nums.size();
		if (!n) return 0;
		//we need to consider n == 1 seperately!
		if (n == 1) return nums[0];
		//from 1 -> n
		for (int i = 1; i < n; ++i) {
			int t = max(a1 + nums[i], b1);
			a1 = b1;
			b1 = t;
		}
		//then from 0 -> n-1
		for (int i = 0; i < n - 1; ++i) {
			int t = max(a2 + nums[i], b2);
			a2 = b2;
			b2 = t;
		}
		return max(b1, b2);
	}
};