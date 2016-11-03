class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		if (!numRows) return res;
		res.push_back({ 1 });
		for (int i = 2; i <= numRows; ++i){
			vector<int> v;
			v.push_back(1);
			for (int j = 1; j < i - 1; ++j)
				v.push_back(res[i - 2][j - 1] + res[i - 2][j]);
			v.push_back(1);
			res.push_back(v);
		}
		return res;
	}
};