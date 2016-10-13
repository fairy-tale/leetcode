class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, vector<int>> m;
		vector<int> ans;
		for (int i = 0; i < nums.size(); ++i)
			m[nums[i]].push_back(i);
		for (int i = 0; i < nums.size() && ans.size() == 0; ++i) {
			int other = target - nums[i];
			if (m.count(other)) {
				for (auto k : m[other]) {
					if (k != i) {
						ans.push_back(i);
						ans.push_back(k);
						break;
					}
				}
			}
		}
		return ans;
	}
};