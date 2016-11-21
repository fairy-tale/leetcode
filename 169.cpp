class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int c = 0;
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (c == 0) res = nums[i];
			if (res == nums[i]) c++;
			else c--;
		}
		return res;
	}
};