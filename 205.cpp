class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> hash;
		unordered_map<char, char> hash2;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (hash.count(s[i])) {
				if (hash[s[i]] != t[i]) return false;
			}
			else {
				hash[s[i]] = t[i];
				if (hash2.count(t[i]) && hash2[t[i]] != s[i]) return false;
				hash2[t[i]] = s[i];
			}
		}
		return true;
	}
};