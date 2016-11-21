class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> res;
		for (int i = 0; i < nums.size() && res.size() == 0; ++i) {
			if (!m.count(nums[i])) {
				m[target - nums[i]] = i;
			}
			else {
				res.push_back(i);
				res.push_back(m[nums[i]]);
			}
		}
		return res;
	}
};