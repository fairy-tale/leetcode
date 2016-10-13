class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<int> d(n, 0);
		for (int j = 0; j < n; ++j){
			if (obstacleGrid[0][j]) break;
			d[j] = 1;
		}
		for (int i = 1; i < m; ++i) {
			d[0] = obstacleGrid[i][0] ? 0 : d[0];
			for (int j = 1; j < n; ++j) {
				d[j] = obstacleGrid[i][j] ? 0 : d[j] + d[j - 1];
			}
		}
		return d[n - 1];

	}
};