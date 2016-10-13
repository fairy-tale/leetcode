class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		if (!n) return -1;
		int start = 0;
		int end = n - 1;
		while (start < end) {
			int mid = start + end >> 1;
			if (nums[start] <= nums[mid]) {
				if (target >= nums[start] && target <= nums[mid]) end = mid;
				else start = mid + 1;
			}
			else{
				if (target >= nums[start] || target <= nums[mid]) end = mid;
				else start = mid + 1;
			}
		}
		if (target == nums[start]) return start;
		else return -1;
	}
};