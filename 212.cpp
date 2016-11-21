//first use trie tree to store all the words
//then based on trie tree, search the whole board.
class Solution {
private:
	struct TrieNode{
		bool leaf;
		TrieNode* children[26];
		TrieNode() : leaf(false) {
			fill_n(children, 26, nullptr);
		}
	};

	TrieNode* root;

	void addWord(string word) {
		TrieNode* t = root;
		for (auto c : word) {
			if (!t->children[c - 'a']) t->children[c - 'a'] = new TrieNode();
			t = t->children[c - 'a'];
		}
		t->leaf = true;
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		unordered_set<string> ans;
		int m = board.size();
		if (!m) return res;
		int n = board[0].size();
		root = new TrieNode();
		for (auto w : words) addWord(w);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				f(board, root, m, n, i, j, ans, "");
			}
		}
		for (auto w : ans) res.push_back(w);
		return res;
	}

	void f(vector<vector<char>>& board, TrieNode* t, int m, int n, int i, int j, unordered_set<string>& ans, string cur) {
		if (i < 0 || i >= m || j < 0 || j >= n) return;
		// can't write here! since we find that c is the leaf in the current recursion, but we add the whole string to result in the next recursion.
		//if (t->leaf) ans.insert(cur);
		char c = board[i][j];
		if (isalpha(c) && t->children[c - 'a']) {
			board[i][j] = ~board[i][j];
			//here, this judgement must be wrote in the if clause!! Otherwise, it will has duplicate result.
			if (t->children[c - 'a']->leaf) ans.insert(cur + c);
			f(board, t->children[c - 'a'], m, n, i + 1, j, ans, cur + c);
			f(board, t->children[c - 'a'], m, n, i - 1, j, ans, cur + c);
			f(board, t->children[c - 'a'], m, n, i, j + 1, ans, cur + c);
			f(board, t->children[c - 'a'], m, n, i, j - 1, ans, cur + c);
			board[i][j] = ~board[i][j];
		}
	}
};