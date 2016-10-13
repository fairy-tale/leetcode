// O(m*n)->copy to another matrix
// O(m+n)->row[m]:bool,col[n]:bool
// In_place-> use first row and first col to store the information
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (!m) return;
		int n = matrix[0].size();
		bool r = true, c = true;
		for (int i = 0; i < m; ++i) {
			if (!matrix[i][0]) {
				c = false;
				break;
			}
		}
		for (int j = 0; j < n; ++j) {
			if (!matrix[0][j]) {
				r = false;
				break;
			}
		}
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j) {
				if (!matrix[i][j]) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j) {
				if (!matrix[i][0] || !matrix[0][j]) {
					matrix[i][j] = 0;
				}
			}
		}
		if (!r) {
			for (int j = 0; j < n; ++j) matrix[0][j] = 0;
		}
		if (!c) {
			for (int i = 0; i < m; ++i) matrix[i][0] = 0;
		}
		return;
	}
};