//similar to solution 1 of 188. dp
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int out1, out2, in1, in2;
		out1 = out2 = 0;
		in1 = in2 = INT_MIN;
		for (int i = 0; i < n; ++i) {
			out1 = max(out1, in1 + prices[i]);
			in1 = max(in1, -prices[i]);
			out2 = max(out2, in2 + prices[i]);
			in2 = max(in2, out1 - prices[i]);
		}
		return out2;
	}
};