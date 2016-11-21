//tirenode :  a bool value represent leaf. a vector store the children
class TrieNode {
public:
	// Initialize your data structure here.
	bool end;
	vector<TrieNode*> children;
	TrieNode() {
		//the variable assignment should be wrote in the constructor.
		//fill() vs fill_n()
		//fill(v.begin(), v.end(), value) it must have end()! so we can't use fill if we don't know the iterator of the end;
		//fill_n(v.begin(), number, value) we only need know the iterator of the start point.
		//so in most cases, fill_n is easier to use.
		vector<TrieNode*> children = vector<TrieNode*>(26);
		fill_n(children.begin(), 26, nullptr);
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* p = root;
		for (auto c : word) {
			if (!p->children[c - 'a'])
				p->children[c - 'a'] = new TrieNode();
			p = p->children[c - 'a'];
		}
		p->end = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* p = root;
		for (auto c : word) {
			if (!p->children[c - 'a']) return false;
			p = p->children[c - 'a'];
		}
		return p->end;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* p = root;
		for (auto c : prefix) {
			if (!p->children[c - 'a']) return false;
			p = p->children[c - 'a'];
		}
		return true;
	}

private:
	TrieNode* root;
};