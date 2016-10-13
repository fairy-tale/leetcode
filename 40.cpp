class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> cur;
		sort(candidates.begin(), candidates.end());
		f(candidates, target, 0, ans, cur);
		return ans;
	}

	void f(vector<int>& candidates, int target, int k, vector<vector<int>>& ans, vector<int>& cur) {
		if (target == 0) {
			ans.push_back(cur);
		}
		else {
			for (int i = k; i < candidates.size(); ++i) {
				if ((i == k || (i && candidates[i] != candidates[i - 1])) && target >= candidates[i]) {
					cur.push_back(candidates[i]);
					f(candidates, target - candidates[i], i + 1, ans, cur);
					cur.pop_back();
				}
				else if (target < candidates[i]) {
					break;
				}
			}
		}
	}
};