//use pointer instead of index!

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		// type of inorder.beign() -> iterator.  iterator != pointer,   so here use '&*inorder.begin()' not 'inorder.begin()'
		return f(&*inorder.begin(), &*inorder.end(), &*postorder.begin(), &*postorder.end());
	}
	//The reason use inorder.end() instead of inorder.end()-1:
	//if use the latter one, when the array is empty,   inorder.end()-1 exceed the range.
	//for the former on, in that case, inorder.begin() == inorder.end()!
	TreeNode* f(int *start1, int *end1, int *start2, int *end2) {
		if (start1 == end1) {
			return NULL;
		}
		else {
			TreeNode* root = new TreeNode(*(end2 - 1));
			//find() can be used to find the index;   end2[-1] is the same as end2-1, it[n] == it+n;
			int *k = find(start1, end1, end2[-1]);
			root->left = f(start1, k, start2, end2 - (end1 - k));
			root->right = f(k + 1, end1, end2 - (end1 - k), end2 - 1);
			return root;
		}
	}
};


//the next time, add the iterative solution!