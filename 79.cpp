class Solution {
// need to record whether the position is visited, using board[r][c] = ~ board[r][c], after recursion, do board[r][c] = ~ board[r][c] again.
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		if (!m) return false;
		int n = board[0].size();
		for (int i = 0; i < m * n; ++i) {
			if (f(board, m, n, word, i / n, i%n, 0)) return true;
		}
		return false;
	}
	bool f(vector<vector<char>>& board, int m, int n, string& word, int r, int c, int k) {
		if (board[r][c] == word[k]) {
			board[r][c] = ~board[r][c];
			if (k + 1 == word.size()) return true;
			if (r + 1 < m && f(board, m, n, word, r + 1, c, k + 1)) return true;
			if (r - 1 >= 0 && f(board, m, n, word, r - 1, c, k + 1)) return true;
			if (c + 1 < n && f(board, m, n, word, r, c + 1, k + 1)) return true;
			if (c - 1 >= 0 && f(board, m, n, word, r, c - 1, k + 1)) return true;
			board[r][c] = ~board[r][c];
		}
		return false;
	}
};