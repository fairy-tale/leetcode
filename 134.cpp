class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int cur = 0, left = 0;
		while (cur < n) {
			int i = 0;
			for (; i < n; ++i) {
				left += gas[(cur + i) % n] - cost[(cur + i) % n];
				if (left < 0) break;
			}
			if (i == n) return cur;
			else {
				left = 0;
				cur = cur + i + 1;
			}
		}
		return -1;
	}
};