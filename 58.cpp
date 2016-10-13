class Solution {
public:
	int lengthOfLastWord(string s) {
		bool start = true;
		int len = 0;
		for (auto c : s) {
			if (c != ' ') {
				if (start){
					start = false;
					len = 0;
				}
				len++;
			}
			else {
				start = true;
			}
		}
		return len;
	}
};