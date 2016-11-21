class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		int n = prerequisites.size();
		vector<vector<int>> edge(numCourses);
		vector<int> res;
		vector<int> degree(numCourses, 0);
		queue<int> leaves;
		for (auto p : prerequisites) {
			degree[p.first]++;
			edge[p.second].push_back(p.first);
		}
		for (int i = 0; i < numCourses; ++i)
			if (!degree[i]) leaves.push(i);
		while (!leaves.empty()) {
			int c = leaves.front();
			leaves.pop();
			res.push_back(c);
			for (auto ne : edge[c])
				if (!--degree[ne])
					leaves.push(ne);
		}
		if (res.size() != numCourses) res.clear();
		return res;
	}
};