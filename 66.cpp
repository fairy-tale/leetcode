class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int step = 1;
		int i = digits.size() - 1;
		while (step && i >= 0) {
			int val = digits[i] + step;
			digits[i--] = val % 10;
			step = val / 10;
		}
		if (step) digits.insert(digits.begin(), step);
		return digits;
	}
};