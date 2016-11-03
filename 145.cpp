//solution1
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		unordered_set<TreeNode*> list;
		stack<TreeNode*> st;
		vector<int> res;
		if (!root) return res;
		st.push(root);
		while (!st.empty()) {
			TreeNode* p = st.top();
			// pop the node on the second visit.
			if (list.count(p)) {
				st.pop();
				res.push_back(p->val);
			}
			else {
				list.insert(p);
				if (p->right) st.push(p->right);
				if (p->left) st.push(p->left);
			}
		}
		return res;
	}
};

//solution 2  reverse the postorder, then middle->right->left, it's the same as preorder, very easy.
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> mystack;
		vector<int> result;
		while (true){
			while (root){
				result.push_back(root->val);
				if (root->left) mystack.push(root->left);
				root = root->right;
			}
			if (mystack.empty()) break;
			root = mystack.top();
			mystack.pop();
		}
		reverse(result.begin(), result.end());
		return result;
	}
};