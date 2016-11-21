class Solution {
public:
	int findMin(vector<int>& nums) {
		int end = nums.size() - 1;
		int start = 0;
		while (start < end) {
			int mid = (start + end) >> 1;
			while (nums[mid] == nums[end] && end > mid) end--;
			if (nums[mid] <= nums[end]) end = mid;
			else start = mid + 1;
		}
		return nums[start];
	}
};