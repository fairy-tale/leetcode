class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int mask = 255;
		for (int i = 0; i < n; ++i)
			for (int j = 0; i + j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
		for (int i = 0; i < n / 2; ++i)
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
		return;
	}
};