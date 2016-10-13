//using array[127] instead of map<char, int>. Run time improves from 64ms to 16ms.

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> m(127, -1);
		int start = 0, end = 0, maxlen = 0;
		for (; end < s.size(); ++end) {
			if (m[s[end]] < start){
				m[s[end]] = end;
			}
			else{
				maxlen = max(maxlen, end - start);
				start = m[s[end]] + 1;
				m[s[end]] = end;
			}
		}
		maxlen = max(maxlen, end - start);
		return maxlen;
	}
};