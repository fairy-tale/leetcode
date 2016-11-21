/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class BSTIterator {
private:
	stack<TreeNode*> st;
public:
	BSTIterator(TreeNode *root) {
		while (root) {
			st.push(root);
			root = root->left;
		}

	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !st.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* p = st.top();
		st.pop();
		int res = p->val;
		p = p->right;
		while (p) {
			st.push(p);
			p = p->left;
		}
		return res;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/