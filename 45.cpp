class Solution {
public:
	int jump(vector<int>& nums) {
		int res = 0;
		int cur = 0;
		int k = 0;
		int n = nums.size();
		while (cur < n - 1) {
			int tmp = cur;
			for (int i = k; i <= cur; ++i)
				tmp = max(tmp, i + nums[i]);
			k = cur + 1;
			cur = tmp;
			res++;
		}
		return res;
	}
};