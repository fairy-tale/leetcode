//solution 1
//xor then find the first bit that m and n are not the same.
//__builtin_clz(unsigned int x)  return the number of leading zero
//__builtin_ctz() return the number of trailing zero
//__builtin_popcount() return the number of 1-bits
//__builtin_ffs() return  the index of the least significant 1-bit
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (__builtin_clz(m) != __builtin_clz(n)) return 0;
		int t = n ^ m;
		return m & (0xffffffff << 31 - __builtin_clz(t));
	}
};

//solution 2  every time remove the least significant '1' in n till n <= m
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (n / 2 >= m) return 0;
		while (m < n)  n &= n - 1;
		return n;
	}
};