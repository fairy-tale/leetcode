//caculate the height for each row(the current row is the bottom). Then caculate the max_area for each row.
//for the sub problem, it's the same as 84.largest Rectangle Area
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (!m) return 0;
		int n = matrix[0].size();
		vector<int> h(n, 0);
		int area = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1') {
					h[j] ++;
				}
				else {
					h[j] = 0;
				}
			}
			area = max(area, helper(h));
		}
		return area;
	}


	int helper(vector<int>& h) {
		stack<int> st;
		if (h.empty()) return 0;
		int area = 0;
		h.push_back(0);
		for (int i = 0; i < h.size(); ++i) {
			if (!st.empty() && h[st.top()] > h[i]) {
				while (!st.empty() && h[st.top()] > h[i]) {
					int k = st.top();
					st.pop();
					if (st.empty()) {
						area = max(area, h[k] * (i));
					}
					else {
						area = max(area, h[k] * (i - st.top() - 1));
					}
				}
			}
			st.push(i);
		}
		return area;
	}
};