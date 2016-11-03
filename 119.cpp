class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		res.push_back(1);
		for (int i = 2; i <= rowIndex + 1; ++i){
			res.push_back(1);
			// from right to left!
			for (int j = i - 2; j >= 1; --j)
				res[j] += res[j - 1];
		}
		return res;
	}
};