//corner case: 1.0 == 1;   .0 < 0.0(not include in test case); 4..1 < 4.1; 4. == 4
class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> v1;
		vector<int> v2;
		int start = 0;
		version1 += '.';
		version2 += '.';
		for (int i = 0; i < version1.size(); ++i) {
			if (version1[i] == '.') {
				int v;
				if (i == start) v = -1;
				else v = stoi(version1.substr(start, i - start));
				v1.push_back(v);
				start = i + 1;
			}
		}
		start = 0;
		for (int i = 0; i < version2.size(); ++i) {
			if (version2[i] == '.') {
				int v;
				if (i == start) v = 0;
				else v = stoi(version2.substr(start, i - start));
				v2.push_back(v);
				start = i + 1;
			}
		}
		int m = v1.size();
		int n = v2.size();
		for (int i = 0; i < min(m, n); ++i) {
			if (v1[i] < v2[i]) return -1;
			if (v1[i] > v2[i]) return 1;
		}
		if (m == n) return 0;
		else if (m > n) {
			int k = n;
			while (k < m && v1[k] == 0) k++;
			return k == m ? 0 : 1;
		}
		else {
			int k = m;
			while (k < n && v2[k] == 0) k++;
			return k == n ? 0 : -1;
		}
	}
};