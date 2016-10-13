class Solution {
public:
	int myAtoi(string input) {
		int i = 0;
		long ans = 0;
		long limit = long(INT_MAX) + 1;
		bool pos = true;
		for (; input[i] == ' ' && i < input.size(); ++i) {}
		if (i == input.size()) return 0;
		if (input[i] == '-' || input[i] == '+')
			pos = input[i++] == '-' ? false : true;
		string x = input.substr(i);
		for (auto c : x){
			if (!isdigit(c)) break;
			if (ans > limit) {
				break;
			}
			ans *= 10;
			ans += c - '0';
		}
		ans = pos ? ans : -ans;
		if (ans > INT_MAX) return INT_MAX;
		if (ans < INT_MIN) return INT_MIN;
		return int(ans);
	}
};