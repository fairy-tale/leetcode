//dfs
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		if (!m) return 0;
		int n = grid[0].size();
		int res = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					res++;
					dfs(grid, i, j, m, n);
				}
			}
		}
		return res;
	}

	void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
		if (grid[x][y] != '1') return;
		grid[x][y] = '2';
		if (x + 1 < m) dfs(grid, x + 1, y, m, n);
		if (x - 1 >= 0) dfs(grid, x - 1, y, m, n);
		if (y + 1 < n) dfs(grid, x, y + 1, m, n);
		if (y - 1 >= 0) dfs(grid, x, y - 1, m, n);
		return;
	}
};