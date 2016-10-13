//since need to record the heights before, use stack.
//two pointer can't be used in this case, since need know all the information between two pointers.
//push_back a '0' at the end of array, which could pop all the heights in array, no missing.
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (!n) return 0;
		int max_area = 0;
		stack<int> s;
		heights.push_back(0);
		s.push(0);
		for (int i = 1; i <= n; ++i) {
			if (heights[s.top()] < heights[i]) {
				s.push(i);
			}
			else if (heights[s.top()] > heights[i]) {
				int last = s.top();
				while (!s.empty() && heights[s.top()] > heights[i]) {
					max_area = max(max_area, heights[s.top()] * (i - s.top()));
					last = s.top();
					s.pop();
				}
				if (s.empty() || heights[s.top()] < heights[i]) {
					heights[last] = heights[i];
					s.push(last);
				}
			}
		}
		return max_area;
	}
};