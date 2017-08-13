#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define re register
typedef long long ll;
int ava[51], clr[51], n, k, q, p, ans, w;
inline int read() {
	int x(0); char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = getchar();
	return x;
}
int main() {
	n = read(); k = read(); q = read();
	for (int i = 1 ;i <= n; ++i) {
		p = read(); w = read();
		clr[p]++;
		if(w <= q) {
			for (int j = 0; j <= k; ++j) ava[j] = clr[j]; 
		}
		ans += ava[p];
		if(ava[p] == clr[p]) ans--;
	}
	printf("%d\n", ans);
	return 0;
}
