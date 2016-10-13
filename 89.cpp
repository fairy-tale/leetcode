//order: 0,1,3,2,6,7,5,4
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		res.push_back(0);
		if (!n) return res;
		res.push_back(1);
		for (int i = 1; i < n; ++i)
			for (int j = (1 << i) - 1; j >= 0; --j)
				res.push_back((1 << i) + res[j]);
		return res;
	}
};