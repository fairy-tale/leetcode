// fantastic solution!
class Solution {
private:
	string l = "MDCLXVI";
public:
	string intToRoman(int num) {
		string ans = "";
		for (int p = 1000, k = 0; p > 0; k += 2, num %= p, p /= 10) {
			int t = num / p;
			switch (t) {
			case 0:
				break;
			case 1 ... 3:
				for (int i = 0; i < t; ++i)
					ans += l[k];
				break;
			case 4:
				ans += l[k];
				ans += l[k - 1];
				break;
			case 5 ... 8:
				ans += l[k - 1];
				for (int i = 0; i < t - 5; ++i)
					ans += l[k];
				break;
			case 9:
				ans += l[k];
				ans += l[k - 2];
			}
		}
		return ans;
	}
};