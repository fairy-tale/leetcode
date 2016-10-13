//there are lots of different test cases... Hard to consider all the corner cases..
//To deal with the duplication, we can search the array till find the first one which is unequal. Then the problem is the same as 33.Search in Rotated Sorted Array
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int n = nums.size();
		if (!n) return false;
		int start = 0, end = n - 1;
		while (start < end) {
			while (start < end && nums[start] == nums[start + 1]) start++;
			int mid = start + end >> 1;
			if (nums[start] == nums[mid] && start != mid) {
				if (target == nums[start]) return true;
				else end = mid - 1;
			}
			else if (nums[start] <= nums[mid]) {
				if (target >= nums[start] && target <= nums[mid]) end = mid;
				else start = mid + 1;
			}
			else {
				if (target <= nums[mid] || target >= nums[start]) end = mid;
				else start = mid + 1;
			}
		}
		return start < n ? nums[start] == target : false;
	}
};