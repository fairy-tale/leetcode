class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t b = 0;
		int i = 0;
		while (n) {
			b <<= 1;
			b |= n & 1;
			n >>= 1;
			i++;
		}
		return b << (32 - i);
	}
};