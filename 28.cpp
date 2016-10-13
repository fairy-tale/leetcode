class Solution {
public:
	int strStr(string haystack, string needle) {
		if (!needle.size()) return 0;
		int m = haystack.size(), n = needle.size();
		for (int i = 0; i <= m - n; ++i) {
			if (haystack[i] == needle[0]) {
				int k = 1;
				while (k < n && haystack[i + k] == needle[k]) k++;
				if (k == n) return i;
			}
		}
		return -1;
	}
};