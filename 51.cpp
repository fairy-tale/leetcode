class Solution {
private:
	vector<vector<string>> res;
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		f(0, n, 0, 0, 0, board);
		return res;
	}
	void f(int r, int n, int c, int cross1, int cross2, vector<string>& board) {
		if (r == n) {
			res.push_back(board);
		}
		else {
			for (int i = 0; i < n; ++i) {
				int t = 1 << i;
				if (!(c & t) && !(cross1 & t) && !(cross2 & t)) {
					board[r][i] = 'Q';
					f(r + 1, n, c | t, (cross1 | t) >> 1, (cross2 | t) << 1, board);
					board[r][i] = '.';
				}
			}
		}
	}

};s