class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int t = 1 << 9;
		vector<int> row = vector<int>(9, t);
		vector<int> col = vector<int>(9, t);
		vector<int> block = vector<int>(9, t);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') continue;
				int n = board[i][j] - '1';
				if (!((row[i] >> n) & 1)) row[i] |= 1 << n;
				else return false;
				if (!((col[j] >> n) & 1)) col[j] |= 1 << n;
				else return false;
				if (!((block[(i / 3) * 3 + j / 3] >> n) & 1)) block[(i / 3) * 3 + j / 3] |= 1 << n;
				else return false;
			}
		}
		return true;
	}
};