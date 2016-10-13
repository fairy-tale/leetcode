//use a array(int[256]) instead of map when the tyep of key is char, save a lot of time
//notice: string t can have duplicate character!
class Solution {
public:
	string minWindow(string s, string t) {
		int hash[256] = { 0 };
		int n = s.size();
		int k = t.size();
		for (auto c : t)  hash[c]++;
		// for the character which doesn't appear in string t, let their hash value be k + 1
		for (int i = 0; i < 256; ++i)
			if (!hash[i]) hash[i] = k + 1;
		int start = -1, min_start = 0, min_len = INT_MAX;
		int count = k;
		for (int i = 0; i < n; ++i) {
			if (hash[s[i]] == k + 1) continue;
			if (hash[s[i]] > 0) {
				if (start < 0) start = i;
				count--;
			}
			hash[s[i]]--;
			while (hash[s[start]] < 0 || hash[s[start]] == k + 1) {
				if (hash[s[start]] < 0) hash[s[start]]++;
				start++;
			}
			if (!count) {
				if (min_len > i - start + 1) {
					min_start = start;
					min_len = i - start + 1;
				}
			}
		}
		return count ? "" : s.substr(min_start, min_len);
	}
};