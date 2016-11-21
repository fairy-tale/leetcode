//notice!! In cmp function, don't change address , like swap(s1, s2); It causes wrong answer.
//till now, I don't know why.

class Solution {
public:
	static bool cmp(const int &n1, const int &n2) {
		string s1 = to_string(n1);
		string s2 = to_string(n2);
		//very good statemnent.
		return s1 + s2 > s2 + s1;
	}

	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		string res = "";
		for (auto n : nums) res += to_string(n);
		if (res[0] == '0') return "0";
		return res;
	}
};