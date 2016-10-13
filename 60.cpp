class Solution {
public:
	string getPermutation(int n, int k) {
		int level = 1;
		string res = "";
		vector<int> hash;
		for (int i = 1; i <= n; ++i)
			hash.push_back(i);
		for (int i = n - 1; i > 0; --i)
			level *= i;
		k--;
		for (int i = n - 1;; --i) {
			int val = k / level;
			res += hash[val] + '0';
			if (!i) break;
			hash.erase(hash.begin() + val);
			k %= level;
			level /= i;
		}
		return res;
	}
};