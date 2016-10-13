class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> res;
		vector<int> ans;
		f(nums, n, 0, n, ans, res);
		return res;
	}

	void f(vector<int>& nums, int n, int cur, int left, vector<int>& ans, vector<vector<int>>& res) {
		if (left >= 0) {
			res.push_back(ans);
			for (int i = cur; i < n; ++i) {
				ans.push_back(nums[i]);
				f(nums, n, i + 1, left - 1, ans, res);
				ans.pop_back();
			}
		}
	}
};