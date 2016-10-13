class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res;
		if (!n) return res;
		res.assign(n, vector<int>(n, 0));
		int k = 1;
		int top = 0, left = 0, bottom = n - 1, right = n - 1;
		int max = n*n;
		while (k <= max) {
			for (int j = left; j <= right; ++j) res[top][j] = k++;
			for (int i = top + 1; i < bottom; ++i) res[i][right] = k++;
			for (int j = right; j > left; --j) res[bottom][j] = k++;
			for (int i = bottom; i > top; --i) res[i][left] = k++;
			left++; right--;
			top++; bottom--;
		}
		return res;
	}
};