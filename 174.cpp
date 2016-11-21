//dp + rolling array
//only need to search from right-bottom to left-top. Since only the latter grids on the path limit the value of current grid, we need to search from end to start.
//we need to do some trick judgement on the conner and bound of the array.
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		if (m == 0) return 0;
		int n = dungeon[0].size();
		if (n == 0) return 0;
		vector<int> dp(n, 0);
		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				int tmp = INT_MAX;
				if (i != m - 1) tmp = dp[j];
				if (j != n - 1) tmp = min(tmp, dp[j + 1]);
				if (tmp == INT_MAX) {
					dp[j] = max(1 - dungeon[i][j], 1);
				}
				else {
					dp[j] = max(tmp - dungeon[i][j], 1);
				}
			}
		}
		return dp[0];
	}
};