// three state 01 -> 10 -> 00
// how to change bit:  0 -> 1  use |mask     1 -> 0 use ^mask
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int a = 0, b = 0;
		for (auto n : nums) {
			a |= (b & n);
			b ^= n;
			//change 11->00
			int tmp = a & b;
			a ^= tmp;
			b ^= tmp;
		}
		return b;
	}
};