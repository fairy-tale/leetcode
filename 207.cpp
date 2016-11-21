class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> degree(numCourses, 0);
		vector<vector<int>> edge(numCourses);
		queue<int> leaves;
		int curCourses = 0;
		for (auto p : prerequisites) {
			degree[p.first]++;
			edge[p.second].push_back(p.first);
		}
		for (int i = 0; i < numCourses; ++i) {
			if (!degree[i]) leaves.push(i);
		}
		while (!leaves.empty()) {
			int t = leaves.size();
			for (int i = 0; i < t; ++i) {
				int leaf = leaves.front();
				leaves.pop();
				curCourses++;
				for (auto ne : edge[leaf]) {
					degree[ne]--;
					if (!degree[ne]) leaves.push(ne);
				}
			}
		}
		return curCourses == numCourses;
	}
};