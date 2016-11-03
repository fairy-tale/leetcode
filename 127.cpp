class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		wordList.insert(endWord);
		int n = wordList.size();
		int m = beginWord.size();
		int level = 1;
		unordered_set<string> list = wordList;
		queue<string> q;
		q.push(beginWord);
		while (!q.empty()) {
			int l = q.size();
			level++;
			for (int i = 0; i < l; ++i) {
				string w = q.front();
				q.pop();
				for (int j = 0; j < m; ++j) {
					for (int k = 'a'; k <= 'z'; ++k) {
						string change = w;
						if (change[j] != k) {
							change[j] = k;
							if (change == endWord) return level;
							if (list.count(change)) {
								q.push(change);
								list.erase(change);
							}
						}
					}
				}
			}
		}
		return 0;
	}
};