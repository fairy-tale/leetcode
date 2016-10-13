class Solution {
private:
	vector<vector<int>> result;
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> v;
		com(v, 1, 0, k, n);
		return result;
	}
	void com(vector<int> v, int low, int len, int k, int n){
		if (len == k){
			result.push_back(v);
			return;
		}
		for (int i = low; i <= n; ++i){
			v.push_back(i);
			com(v, i + 1, len + 1, k, n);
			v.pop_back();
		}
	}
};