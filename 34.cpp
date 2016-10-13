class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		int n = nums.size();
		if (!n) return res;
		int start = 0;
		int end = n - 1;
		int left = -1, right = -1;
		while (start <= end) {
			int mid = start + end >> 1;
			if (nums[mid] < target) {
				start = mid + 1;
			}
			else if (nums[mid] == target && (!mid || (nums[mid - 1] < nums[mid]))) {
				left = mid;
				break;
			}
			else {
				end = mid - 1;
			}
		}
		if (left == -1) return res;
		start = left;
		end = n - 1;
		while (start <= end) {
			int mid = start + end >> 1;
			if (nums[mid] > target) {
				end = mid - 1;
			}
			else if (nums[mid] == target && (mid == n - 1 || nums[mid + 1] > nums[mid])) {
				right = mid;
				break;
			}
			else {
				start = mid + 1;
			}
		}
		res[0] = left;
		res[1] = right;
		return res;

	}
};