//only need find one! binary search
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int start = 0;
		int end = nums.size() - 1;
		while (start < end) {
			int mid = (start + end) >> 1;
			int a = mid ? nums[mid - 1] : INT_MIN;
			int b = mid != nums.size() - 1 ? nums[mid + 1] : INT_MIN;
			if (nums[mid] >= a && nums[mid] >= b) return mid;
			if (nums[mid] < a) end = mid;
			else start = mid + 1;
		}
		return start;
	}
};