class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (!m) return false;
		int n = matrix[0].size();
		int start = 0, end = m * n - 1;
		while (start < end) {
			int mid = start + end >> 1;
			if (matrix[mid / n][mid%n] < target) {
				start = mid + 1;
			}
			else {
				end = mid;
			}
		}
		return matrix[start / n][start%n] == target;
	}
};