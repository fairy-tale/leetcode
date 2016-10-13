class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		if (!n) return;
		int left = 0, right = n - 1;
		int k = left;
		while (k <= right) {
			if (nums[k] == 2) {
				swap(nums[k], nums[right--]);
			}
			else if (nums[k] == 1) {
				k++;
			}
			else {
				swap(nums[k], nums[left++]);
				k++;
			}
		}
		return;
	}
};