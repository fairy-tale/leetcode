//O(nlog(n)) binary search
//suppose we have [1,4,4] s = 4;
//first caculate the sum, sum = [0,1,5,8]
//then for each sum >= s,  caculate the max sum it could minus.
//For 5, 5 - 4 = 1, so we need to find the biggest sum smaller than 1 in the sum array.
//Here we can use binary search.
//or, simply, up = upper_bound(sum.begin(), sum.begin()+i, sum[i]-s); it return the iteator of first value greater than sum[i] - s
// than up - sum.begin();
//lower_bound(v.begin(), v.end(), val) return the iterator of first value greater than or equal to the val.
//http://www.cplusplus.com/reference/algorithm/lower_bound/
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		vector<int> sum(n + 1, 0);
		int res = n + 1;
		for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];
		for (int i = 1; i <= n; ++i) {
			if (sum[i] >= s) {
				int t = sum[i] - s;
				int start = 0;
				int end = i;
				while (start < end) {
					int mid = start + end >> 1;
					if (sum[mid] <= t) {
						start = mid + 1;
					}
					else {
						end = mid;
					}
				}
				res = min(res, i - start + 1);
			}
		}
		return res > n ? 0 : res;
	}
};


class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if (!n) return 0;
		int res = n + 1;
		int sum = 0;
		int start = 0;
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			while (sum >= s) {
				res = min(res, i - start + 1);
				sum -= nums[start++];
			}
		}
		return res > n ? 0 : res;

	}
};