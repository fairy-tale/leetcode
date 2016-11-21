// Sieve of Eratosthenes
class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2) return 0;
		vector<bool> visited(n, false);
		int end = sqrt(n);
		int res = 0;
		for (int i = 2; i < n; ++i) {
			if (!visited[i]) {
				visited[i] = true;
				if (i <= end) {
					for (int j = i * i; j < n; j += i)
						visited[j] = true;
				}
				res++;
			}
		}
		return res;
	}
};