class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<int> d(n);
		d[0] = grid[0][0];
		for (int j = 1; j < n; ++j)
			d[j] = grid[0][j] + d[j - 1];
		for (int i = 1; i < m; ++i) {
			d[0] += grid[i][0];
			for (int j = 1; j < n; ++j) {
				d[j] = grid[i][j] + min(d[j], d[j - 1]);
			}
		}
		return d[n - 1];
	}
};