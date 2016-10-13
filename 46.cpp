//solution1, dfs
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> cur;
		vector<bool> visited(nums.size(), false);
		f(nums, cur, ans, visited, 0);
		return ans;
	}

	void f(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans, vector<bool>& visited, int k) {
		if (k == nums.size()) {
			ans.push_back(cur);
		}
		else {
			for (int i = 0; i < nums.size(); ++i) {
				if (!visited[i]) {
					visited[i] = true;
					cur.push_back(nums[i]);
					f(nums, cur, ans, visited, k + 1);
					cur.pop_back();
					visited[i] = false;
				}
			}
		}
	}
};

// solution2, constant space
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		f(nums, ans, 0);
		return ans;
	}

	void f(vector<int>& nums, vector<vector<int>>& ans, int k) {
		if (k == nums.size()) {
			ans.push_back(nums);
		}
		else {
			for (int i = k; i < nums.size(); ++i) {
				swap(nums[k], nums[i]);
				f(nums, ans, k + 1);
				swap(nums[k], nums[i]);
			}
		}
	}
};