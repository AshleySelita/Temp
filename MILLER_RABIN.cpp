#include <cstdio>
#include <ctime>
#include <cstdlib>
int numy, numn;
inline int read() {
	int x(0); char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + (ch - '0'), ch = getchar();
	return x;
}
inline int mul(int x, int num, int mod) {
	int tmp = x % mod;
	int ans = 0;
	while (num) {
		if(num & 1) ans = (ans + tmp) % mod;
		tmp = (tmp + tmp) % mod;
		num >>= 1;
	}
	return ans;
}
inline int pow(int x, int num, int mod) {
	int tmp = x % mod;
    int ans = 1;
    while (num)
    {
        if(num & 1) ans = mul(ans, tmp, mod);
        tmp = mul(tmp, tmp, mod);
        num >>= 1;
    }
    return ans;
}
inline bool miller_rabin(int n) {
	if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11) return true;
	if(n <= 1 || !(n % 2) || !(n % 3) || !(n % 5) || !(n % 7) || !(n % 11)) return false;
	int k(0), u(n - 1), x, pre;
	while(!(u & 1)) k++, u >>= 1;
	srand((int)time(NULL));
	for (int i = 1; i <= 3; ++i) {
		x = rand() % (n - 2) + 2;
		x = pow(x, u, n);
		pre = x;
		for (int j = 1; j <= k; ++j) {
			x = mul(x, x, n);
			if(x == 1 && pre != 1 && pre != n - 1) return false;
			pre = x;
		}
		if(x != 1) return false;
	}
	return true;
	
}
int main() {
	int n, m, k;
	n = read(); m = read();
	for (int i = 1; i <= m; ++i) {
		k = read();
		if(miller_rabin(k)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
