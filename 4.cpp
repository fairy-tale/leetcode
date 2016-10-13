class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l1 = nums1.size(), l2 = nums2.size();
		int mid = l1 + l2 + 1 >> 1;  //   + 1 is very important, otherwise cases like : nums1 = [], nums2 = [1] -> runtime error.
		bool even = (l1 + l2) % 2 == 0;
		int index1 = 0, index2 = 0;
		double ans1, ans2;
		nums1.push_back(INT_MAX);
		nums2.push_back(INT_MAX);
		while (mid > 1) {
			int k1 = mid >> 1, k2 = mid - k1;
// if index2 + k2 > l2, it means that from nums1[index1] to nums1[index1+k1-1], all the nums are smaller than median! 
			if (index2 + k2 > l2 || (index1 + k1 <= l1 && (nums1[index1 + k1 - 1] <= nums2[index2 + k2 - 1]))) {
				index1 += k1;
				mid = k2;
			}
			else {
				index2 += k2;
				mid = k1;
			}
		}
		ans1 = index2 >= l2 || (index1 < l1 && nums1[index1] < nums2[index2]) ? nums1[index1++] : nums2[index2++];
		ans2 = index2 >= l2 || (index1 < l1 && nums1[index1] < nums2[index2]) ? nums1[index1] : nums2[index2];

		return  even ? (ans1 + ans2) / 2 : ans1;

	}
};