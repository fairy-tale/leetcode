//see comment in 106.
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		return f(preorder, inorder, 0, n - 1, 0, n - 1);
	}
	TreeNode* f(vector<int>& preorder, vector<int>& inorder, int start1, int end1, int start2, int end2) {
		if (start1 > end1) {
			return NULL;
		}
		else {
			TreeNode(*root) = TreeNode(preorder[start1]);
			int k = start2;
			while (inorder[k] != preorder[start1]) k++;
			root->left = f(preorder, inorder, start1 + 1, start1 + k - start2, start2, k - 1);
			root->right = f(preorder, inorder, start1 + k - start2 + 1, end1, k + 1, end2);
			return root;
		}
	}
};