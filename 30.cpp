//  640ms o(n^2)
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		int n = words.size();
		if (!n) return res;
		unordered_map<string, int> hash;
		unordered_map<string, int> tmp = hash;
		int l = words[0].size();
		int m = s.size();
		if (n*l > m) return res;
		for (auto w : words) hash[w]++;
		for (int k = 0; k <= m - l; ++k) {
			int i = k;
			tmp.clear();
			for (; i <= m - l; i += l) {
				string s1 = s.substr(i, l);
				if (!hash.count(s1) || ++tmp[s1] > hash[s1]) break;
			}
			if (i - k == n*l) res.push_back(k);
		}
		return res;
	}
};

//50ms o(l*n) l -> length of the word. move the window every time.
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		int n = words.size();
		if (!n) return res;
		unordered_map<string, int> hash;
		unordered_map<string, int> tmp;
		unordered_map<string, queue<int>> index;  //store the index of each word.
		int l = words[0].size();
		int m = s.size();
		// if (l * n > m) return res;
		for (auto w : words) hash[w]++;
		int k = 0;
		while (k < l) {
			index.clear();
			tmp.clear();
			int left = k;
			for (int i = left; i <= m - l; i += l) {
				string s1 = s.substr(i, l);
				if (hash.count(s1)) {
					// delete the word on the left side of the window.
					if (!index[s1].empty()) {
						while (!index[s1].empty() && index[s1].front() < left) {
							tmp[s1]--;
							index[s1].pop();
						}
					}
					if (++tmp[s1] > hash[s1]) {
						left = index[s1].front() + l;
						index[s1].pop();
						tmp[s1]--;
					}
					index[s1].push(i);
					if (i - left == (n - 1)*l) res.push_back(left);
				}
				else {
					tmp.clear();
					index.clear();
					left = i + l;
				}
			}
			++k;
		}
		return res;
	}
};