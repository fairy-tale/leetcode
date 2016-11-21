// begin with '0x': hexadecimal;    begin with '0': octonary;   other : decimal;  no binary
// end with 'u' : unsigned;   end with 'l' long int
// how to encode A. C. G. T:
// A => 0x41;   C => 0x43  ; G => 0x47;  T=> 0x54;     use the last 3 bits!
// or  A => 65 + 1 % 5 = 1	C => 67 + 1 %5 = 3  G=> 71 + 1% 5 = 2    T=> 84 + 1 % 5 = 0        only use 2 bits !
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<int, int> hash;
		vector<string> res;
		int n = s.size();
		int i = 0;
		int t = 0;
		while (i < min(n, 9))
			t = t << 2 | (s[i++] + 1) % 5;
		while (i < n) {
			t = t << 2 & 0xfffff | (s[i++] + 1) % 5;
			hash[t]++;
			if (hash[t] == 2) res.push_back(s.substr(i - 10, 10));
		}
		return res;
	}
};
