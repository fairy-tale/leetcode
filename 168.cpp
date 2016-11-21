class Solution {
public:
	string convertToTitle(int n) {
		string res = "";
		while (n) {
			// here 26 % 26 = 0 but 26 => 'Z'
			int k = (n - 1) % 26;
			char t = 'A' + k;
			res = t + res;
			n = (n - 1) / 26;
		}
		return res;
	}
};