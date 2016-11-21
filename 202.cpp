class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0) return false;
		unordered_set<int> m;
		while (true) {
			int tmp = 0;
			while (n) {
				tmp += (n % 10) * (n % 10);
				n /= 10;
			}
			if (tmp == 1) return true;
			if (m.count(tmp)) return false;
			else {
				m.insert(tmp);
				n = tmp;
			}
		}
		return true;
	}
};