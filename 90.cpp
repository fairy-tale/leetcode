//need sort first
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<int> v;
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		f(nums, n, 0, res, v);
		return res;
	}

	void f(vector<int>& nums, int n, int cur, vector<vector<int>>& res, vector<int> v) {
		res.push_back(v);
		for (int i = cur; i < n; ++i) {
			if (i == cur || nums[i] != nums[i - 1]) {
				v.push_back(nums[i]);
				f(nums, n, i + 1, res, v);
				v.pop_back();
			}
		}
	}
};