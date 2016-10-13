class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		if (l >= r) return 0;
		int max_area = 0;
		while (l < r) {
			max_area = max(max_area, (r - l) * min(height[l], height[r]));
			if (height[l] < height[r]) l++;
			else r--;
		}
		return max_area;
	}
};