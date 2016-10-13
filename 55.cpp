class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		if (n == 0 || n == 1) return true;
		int cur = 0;
		for (int i = 0; i < n - 1 && i <= cur; ++i) {
			cur = max(cur, i + nums[i]);
			if (cur >= n - 1) return true;
		}
		return false;
	}
};