// not easy to accept in one submission
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size();
		if (!m) return res;
		int n = matrix[0].size();
		int top = 0, left = 0, bottom = m - 1, right = n - 1;
		int i = 0, j = 0;
		while (true) {
			while (j <= right)
				res.push_back(matrix[i][j++]);
			top++;
			i++;
			j--;
			if (i > bottom) break;
			while (i <= bottom)
				res.push_back(matrix[i++][j]);
			right--;
			j--;
			i--;
			if (j < left) break;
			while (j >= left)
				res.push_back(matrix[i][j--]);
			bottom--;
			i--;
			j++;
			if (i < top) break;
			while (i >= top)
				res.push_back(matrix[i--][j]);
			left++;
			j++;
			i++;
			if (j > right) break;
		}
		return res;
	}
};