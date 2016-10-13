class Solution {
public:
	int mySqrt(int x) {
		if (x == 0 || x == 1) return x;
		int end = 46340;
		int start = 2;
		while (start <= end) {
			int mid = start + end >> 1;
			if (mid * mid < x) {
				start = mid + 1;
			}
			else if (mid * mid > x){
				end = mid - 1;
			}
			else {
				return mid;
			}
		}
		return end;
	}
};