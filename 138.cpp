//solution1. without hashmap.   add a copy directly after the node;   -1->-2->-3 :  -1->-1->-2->-2->-3->-3
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode* p = head;
		RandomListNode* head1;
		if (!head) return NULL;
		while (p) {
			RandomListNode* p_copy = new RandomListNode(p->label);
			p_copy->next = p->next;
			p->next = p_copy;
			p = p->next->next;
		}
		p = head;
		head1 = p->next;
		//add random pointer
		while (p) {
			p->next->random = p->random ? p->random->next : NULL;
			p = p->next->next;
		}
		p = head;
		//recover two list
		while (p) {
			RandomListNode* co = p->next;
			p->next = co->next;
			co->next = co->next ? co->next->next : NULL;
			p = p->next;
		}
		return head1;
	}
};

//solution2 with hashmap
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*, RandomListNode*> hash;
		RandomListNode* p = head;

		while (p) {
			RandomListNode* p_copy = new RandomListNode(p->label);
			hash[p] = p_copy;
			p = p->next;
		}
		p = head;
		while (p) {
			hash[p]->next = p->next ? hash[p->next] : NULL;
			hash[p]->random = p->random ? hash[p->random] : NULL;
			p = p->next;
		}
		return hash[head];
	}
};