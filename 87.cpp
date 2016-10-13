// O(n^4) dp[a][b][c] a->start of s1; b-> end of s1; c-> start of s2
//bool dp[n][n][n] is much faster than vector<vector<vector<bool>>> dp
//Check s1[i1][j1] has the same character as s2[i2][j2] (same length), this prune could reduce the run time from 16ms -> 3ms
//use hash to prune! fantastic!
class Solution {
private:
	const int primes[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
public:
	bool isScramble(string s1, string s2) {
		int n = s1.size();
		if (n != s2.size()) return false;
		//much fast than vector!
		bool dp[n][n][n];
		int hash1[n][n], hash2[n][n];
		// a way to set the value for array.
		memset(dp, false, sizeof(dp));
		//hash, mulitple primes, same value iff with same character.
		for (int i = 0; i < n; ++i) {
			hash1[i][i] = primes[s1[i] - 'a'];
			hash2[i][i] = primes[s2[i] - 'a'];
			for (int j = i + 1; j < n; ++j){
				hash1[i][j] = hash1[i][j - 1] * primes[s1[j] - 'a'];
				hash2[i][j] = hash2[i][j - 1] * primes[s2[j] - 'a'];
			}
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i + k < n; ++i) {
				for (int j = 0; j + k < n; ++j) {
					if (k == 0) {
						dp[i][i][j] = s1[i] == s2[j];
					}
					else {
						//check whether has the same character
						if (hash1[i][i + k] == hash2[j][j + k]){
							for (int c = i; c < i + k; ++c) {
								int l1 = c - i + 1, l2 = k + 1 - l1;
								if ((dp[i][c][j] && dp[c + 1][i + k][j + l1]) || (dp[i][c][j + l2] && dp[c + 1][i + k][j])){
									dp[i][i + k][j] = true;
									break;
								}
							}
						}
					}
				}
			}
		}
		return dp[0][n - 1][0];
	}
};