class Solution {
public:
	int totalNQueens(int n) {
		int res = 0;
		f(0, n, 0, 0, 0, res);
		return res;
	}
	void f(int r, int n, int c, int cross1, int cross2, int& res) {
		if (r == n) {
			res++;
		}
		else {
			for (int i = 0; i < n; ++i) {
				int t = 1 << i;
				if (!(c & t) && !(cross1 & t) && !(cross2 & t)) {
					f(r + 1, n, c | t, (cross1 | t) >> 1, (cross2 | t) << 1, res);
				}
			}
		}
	}
};