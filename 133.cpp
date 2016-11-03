//using map to store the map from origin to copy.
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		queue<UndirectedGraphNode*> q;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>  hash;
		if (!node) return NULL;
		hash[node] = new UndirectedGraphNode(node->label);
		q.push(node);
		while (!q.empty()) {
			UndirectedGraphNode* p = q.front();
			q.pop();
			for (auto& ne : p->neighbors) {
				if (!hash.count(ne)) {
					hash[ne] = new UndirectedGraphNode(ne->label);
					q.push(ne);
				}
				hash[p]->neighbors.push_back(hash[ne]);
			}
		}
		return hash[node];
	}
};