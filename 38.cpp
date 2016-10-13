class Solution {
public:
	string countAndSay(int n) {
		string ans = "1";
		while (n > 1) {
			n--;
			string tmp = "";
			int count = 1;
			for (int i = 0; i < ans.size(); ++i) {
				if (i < ans.size() - 1 && ans[i] == ans[i + 1]) {
					count++;
				}
				else {
					tmp += (count + '0');
					tmp += ans[i];
					count = 1;
				}
			}
			ans = tmp;
		}
		return ans;
	}
};