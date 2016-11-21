class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (!numerator) return "0";
		if (!denominator) return "INF";
		long nu = numerator, de = denominator;
		bool flag = (nu > 0) ^ (de > 0);
		string res = "";
		int k = 0, start = -1;
		unordered_map<long, int> index;
		if (flag) nu = -nu;
		// or caculate the integer part outside the loop.
		while (nu != 0) {
			long c = nu / de;
			long left = nu % de;
			if (res == "") {
				res += to_string(c);
				res += ".";
				k = res.size();
			}
			else {
				res += to_string(c);
			}

			if (index.count(left)) {
				start = index[left];
				break;
			}
			index[left] = k++;
			nu = left * 10;
		}
		if (start != -1) {
			res = res.insert(start, "(");
			res += ')';
		}
		if (flag) res = "-" + res;
		if (res.back() == '.') res = res.substr(0, res.size() - 1);
		return res;
	}
};