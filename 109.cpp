class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		ListNode* fast = head;
		ListNode **slow = &head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = &(*slow)->next;
		}
		TreeNode* root = new TreeNode((*slow)->val);
		ListNode* tmp = (*slow)->next;
		*slow = NULL;
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(tmp);
		return root;
	}
};