class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		bool final = false;
		int i = n - 2;
		for (; i >= 0; --i)
			if (nums[i] < nums[i + 1]) break;
		if (i >= 0) {
			int k = n - 1;
			while (nums[i] >= nums[k]) k--;
			swap(nums[i], nums[k]);
		}
		int left = i + 1;
		int right = n - 1;
		while (left < right) swap(nums[left++], nums[right--]);
		return;

	}
};