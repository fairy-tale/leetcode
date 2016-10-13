class Solution {
private:
	vector<int> row_check, col_check, blo_check;
public:
	void solveSudoku(vector<vector<char>>& board) {
		row_check = vector<int>(9, 1 << 9);
		col_check = vector<int>(9, 1 << 9);
		blo_check = vector<int>(9, 1 << 9);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int tmp = board[i][j] - '1';
					row_check[i] |= 1 << tmp;
					col_check[j] |= 1 << tmp;
					blo_check[(i / 3) * 3 + j / 3] |= 1 << tmp;
				}
			}
		}
		f(board, 0, 0);
	}

	bool f(vector<vector<char>>& board, int r, int c){
		if (r == 9) return true;
		if (board[r][c] != '.') {
			return f(board, r + (c + 1) / 9, (c + 1) % 9);
		}
		else {
			for (int i = 0; i < 9; ++i) {
				char t = '1' + i;
				if (check(i, r, c)) {
					board[r][c] = t;
					row_check[r] |= 1 << i;
					col_check[c] |= 1 << i;
					blo_check[(r / 3) * 3 + c / 3] |= 1 << i;
					if (f(board, r + (c + 1) / 9, (c + 1) % 9))  return true;
					board[r][c] = '.';
					int k = (~(1 << 9) ^ (1 << i));
					row_check[r] &= k;
					col_check[c] &= k;
					blo_check[(r / 3) * 3 + c / 3] &= k;
				}
			}
			return false;
		}
	}
	bool check(int ch, int r, int c) {
		if (row_check[r] >> ch & 1) return false;
		if (col_check[c] >> ch & 1) return false;
		if (blo_check[(r / 3) * 3 + c / 3] >> ch & 1) return false;
		return true;
	}
};