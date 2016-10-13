// solution1 two point 56ms
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		int n = nums.size();
		for (int i = 0; i < n - 2; ++i) {
			if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;     // prune1;
			if (nums[i] + nums[n - 1] + nums[n - 2] < 0) continue; // prune2;
			if (i && nums[i] == nums[i - 1]) continue;
			int start = i + 1;
			int end = n - 1;
			while (start < end) {
				if (nums[i] + nums[start] + nums[end] == 0) {
					ans.push_back({ nums[i], nums[start++], nums[end--] });
					while (start < end && nums[start] == nums[start - 1]) start++;
					while (start < end && nums[end] == nums[end + 1]) end--;
				}
				else if (nums[i] + nums[start] + nums[end] < 0) {
					start++;
				}
				else {
					end--;
				}
			}
		}
		return  ans;
	}
};

//solution2 hashmap  79ms
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		unordered_map<int, int> m;
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i)
			m[nums[i]] = i;
		for (int i = 0; i < nums.size(); ++i) {
			if (i  && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < nums.size(); ++j) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int tmp = -nums[i] - nums[j];
				if (m.count(tmp) && m[tmp] > j) {
					ans.push_back({ nums[i], nums[j], tmp });
				}
			}
		}
		return ans;
	}
};
