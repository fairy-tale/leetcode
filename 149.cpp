//for a new slope, add 2 !
//clear hash map every loop.
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int n = points.size();
		if (n <= 1) return n;
		int res = 1;
		for (int i = 0; i < n; ++i) {
			unordered_map<double, int> hash;
			int t = 0, ans = 1, k1 = 0;
			for (int j = i + 1; j < n; ++j) {
				// x1 = x2
				if (points[i].x == points[j].x) {
					//y1 = y2, same point
					if (points[i].y == points[j].y) {
						t++;
					}
					//y1 != y2, inf
					else {
						k1 = k1 ? k1 + 1 : 2;
						ans = max(ans, k1);
					}
				}
				else {
					double k = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
					if (hash.count(k)) hash[k]++;
					else hash[k] = 2;
					ans = max(ans, hash[k]);
				}
			}
			res = max(res, ans + t);
		}
		return res;
	}
};