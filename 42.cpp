// stack
class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> st;
		int area = 0;
		st.push(0);
		for (int i = 1; i < height.size(); ++i) {
			if (height[i] >= height[st.top()]) {
				int bottom = height[st.top()];
				st.pop();
				while (!st.empty()) {
					int left = st.top();
					int l_height = height[st.top()];
					area += (i - left - 1) * (min(l_height, height[i]) - bottom);
					if (height[st.top()] > height[i]) break;
					bottom = height[st.top()];
					st.pop();
				}
			}
			st.push(i);
		}
		return area;
	}
};

// two pointer
class Solution {
public:
	int trap(vector<int>& height) {
		int area = 0;
		int left = 0;
		int right = height.size() - 1;
		int hr = 0, hl = 0;
		while (left <= right) {
			if (hl < hr) {
				if (hl > height[left]) area += hl - height[left++];
				else hl = height[left++];
			}
			else {
				if (hr > height[right]) area += hr - height[right--];
				else hr = height[right--];
			}
		}
		return area;
	}
};