//use trie tree is much faster than hashmap since trie tree is pruning during dfs
struct TrieNode {
	bool leaf;
	TrieNode* children[26];
	TrieNode() : leaf(false) {
		fill_n(children, 26, nullptr);
	}
};

class WordDictionary {
private:
	TrieNode* root = new TrieNode();

	bool helper(string word, int cur, TrieNode* t) {
		if (!t) return false;
		if (cur == word.size()) return t->leaf;
		if (word[cur] == '.') {
			for (char c = 'a'; c <= 'z'; ++c) {
				if (helper(word, cur + 1, t->children[c - 'a'])) return true;
			}
			return false;
		}
		else {
			return helper(word, cur + 1, t->children[word[cur] - 'a']);
		}
	}
public:

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode* t = root;
		for (auto c : word) {
			if (!t->children[c - 'a']) t->children[c - 'a'] = new TrieNode();
			t = t->children[c - 'a'];
		}
		t->leaf = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return helper(word, 0, root);
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");