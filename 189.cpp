//solotion 1  in place
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		if (n <= 1) return;
		k %= n;
		if (!k) return;
		k = n - k;
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
		reverse(nums.begin(), nums.end());
	}
};

//solution 2 in place
//首先O(1) space, 就要考虑swap的方法，最直接的方法就是每次确定一个点的位置，然后再找被填的点的位置
//但是，如何确定是不是所有的点都被换过了呢？ 可能会有点一次并不能扫到
// 对于第一个点来说， 它的下一个位置是 k, k位置的点的下一个位置就是 2k % n, 于是看它是否成环只需要看
//是否存在 k * a = n * b 此处 n 为数组长度。  显然如果不互质，必然有环
//接下来就是到底有几个环？ 初始位置从0开始， 然后1,2,3。。到哪个点开始就出现在之前的环里呢？ 
//此处为k,n最大公约数，为什么？暂时给不出一个浅显易懂的思路
//gcd 好好学！
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		int d = gcd(k, n);
		for (int i = 0; i < d; ++i) {
			int j = i;
			int tmp = nums[i];
			while (true) {
				j = (j + k) % n;
				int tmp1 = nums[j];
				nums[j] = tmp;
				tmp = tmp1;
				if (j == i) break;
			}
		}
		return;
	}

	int gcd(int a, int b) {
		int t = b;
		while (t) {
			t = a % b;
			a = b;
			b = t;
		}
		return a;
	}
};
