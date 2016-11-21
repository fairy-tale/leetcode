// even though sort, still o(n), but only o(1) space
// two pointer, from left and right to middle.
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int n = numbers.size();
		int start = 0, end = n - 1;
		vector<int> res(2, -1);
		while (start < end) {
			if (numbers[start] + numbers[end] > target) {
				end--;
			}
			else if (numbers[start] + numbers[end] < target) {
				start++;
			}
			else {
				res[0] = start + 1;
				res[1] = end + 1;
				break;
			}
		}
		return res;
	}
};