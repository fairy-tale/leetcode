class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> cur;
		sort(nums.begin(), nums.end());
		vector<bool> visited(nums.size(), false);
		f(nums, cur, ans, visited, 0);
		return ans;
	}

	void f(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans, vector<bool>& visited, int k) {
		if (k == nums.size()) {
			ans.push_back(cur);
		}
		else {
			unordered_set<int> d;
			d.clear();
			for (int i = 0; i < nums.size(); ++i) {
				if (!visited[i] && !d.count(nums[i])) {
					visited[i] = true;
					d.insert(nums[i]);
					cur.push_back(nums[i]);
					f(nums, cur, ans, visited, k + 1);
					cur.pop_back();
					visited[i] = false;
				}
			}
		}
	}
};