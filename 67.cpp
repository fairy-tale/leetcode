class Solution {
public:
	string addBinary(string a, string b) {
		int m = a.size();
		int n = b.size();
		string res(max(m, n) + 1, ' ');
		int step = 0;
		int k = res.size() - 1, ka = m - 1, kb = n - 1;
		while (step || ka >= 0 || kb >= 0){
			int val1 = ka >= 0 ? a[ka--] - '0' : 0;
			int val2 = kb >= 0 ? b[kb--] - '0' : 0;
			res[k--] = val1^val2^step + '0';
			step = (val1 + val2 + step) / 2;
		}
		if (res[0] == ' ') res.erase(res.begin());
		return res;
	}
};