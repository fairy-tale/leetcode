class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int min_value = INT_MAX;
		int res = 0;
		for (auto p : prices) {
			min_value = min(p, min_value);
			res = max(p - min_value, res);
		}
		return res;
	}
};