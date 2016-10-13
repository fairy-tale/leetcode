class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int n = nums.size();
		if (!n) return 0;
		int start = 0;
		int end = n - 1;
		while (start < end) {
			int mid = start + end >> 1;
			if (nums[mid] > target) {
				end = mid - 1;
			}
			else if (nums[mid] < target) {
				start = mid + 1;
			}
			else {
				return mid;
			}
		}
		if (nums[start] >= target) {
			return start;
		}
		else  {
			return start + 1;
		}
	}
};