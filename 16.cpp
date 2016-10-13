class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int min_dif = INT_MAX / 2;
		int n = nums.size();
		for (int i = 0; i < n - 2; ++i) {
			if (i && nums[i] == nums[i - 1]) continue;
			int start = i + 1;
			int end = n - 1;
			while (start < end) {
				int tmp = nums[i] + nums[start] + nums[end];
				if (tmp == target) {
					return target;
				}
				else if (tmp < target) {
					if (target - tmp < abs(target - min_dif)) min_dif = tmp;
					start++;
				}
				else {
					if (tmp - target < abs(target - min_dif)) min_dif = tmp;
					end--;
				}
			}
		}
		return min_dif;
	}
};