// one more loop than 3sum
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n - 3; ++i) {
			if (i && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < n - 2; ++j) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int start = j + 1;
				int end = n - 1;
				int tmp = target - nums[i] - nums[j];
				while (start < end) {
					if (nums[start] + nums[end] == tmp) {
						ans.push_back({ nums[i], nums[j], nums[start++], nums[end--] });
						while (start < end && nums[start] == nums[start - 1]) start++;
						while (start < end && nums[end] == nums[end + 1]) end--;
					}
					else if (nums[start] + nums[end] < tmp){
						start++;
					}
					else {
						end--;
					}
				}
			}
		}
		return ans;
	}
};