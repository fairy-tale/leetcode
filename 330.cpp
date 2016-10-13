class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		long cur = 0;
		int res = 0;
		int i = 0;
		while (cur < n) {
			if (i < nums.size() && cur + 1 >= nums[i]) {
				cur += nums[i++];
			}
			else {
				res++;
				cur += cur + 1;
			}
		}
		return res;
	}
};