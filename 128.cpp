//solution 1 union-find
//http://blog.csdn.net/dm_vincent/article/details/7655764
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> id;
		unordered_map<int, int> len;
		int res = 0;
		for (auto n : nums) {
			if (!id.count(n)){
				id[n] = n;
				len[n] = 1;
				if (id.count(n - 1)) f_union(id, len, n, n - 1);
				if (id.count(n + 1)) f_union(id, len, n, n + 1);
			}
		}
		for (auto n : nums)
			res = max(res, len[n]);
		return res;
	}


	void f_union(unordered_map<int, int>& id, unordered_map<int, int>& len, int n1, int n2) {
		int root1 = f_find(id, n1);
		int root2 = f_find(id, n2);
		if (root1 != root2) {
			//make the tree balanced, the root of the large tree should be the new root.
			if (len[root1] > len[root2]) {
				id[root2] = root1;
				len[root1] += len[root2];
			}
			else {
				id[root1] = root2;
				len[root2] += len[root1];
			}
		}
	}

	int f_find(unordered_map<int, int>& id, int n) {
		while (n != id[n]) {
			//here, compress the tree. let the parent be the grandparent
			id[n] = id[id[n]];
			n = id[n];
		}
		return n;
	}
};

//solution2
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s;
		int res = 0;
		for (auto n : nums)
			s.insert(n);
		for (auto n : s) {
			int i = 1;
			int tmp = n;
			while (s.count(--tmp)) {
				i++;
				s.erase(tmp);
			}
			tmp = n;
			while (s.count(++tmp)) {
				i++;
				s.erase(tmp);
			}
			res = max(res, i);
		}
		return res;

	}
};