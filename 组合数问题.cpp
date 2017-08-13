#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
int n, m, k, t, a, b, ans;
int f[2001][2001], sa[2001][2001];
int main() {
	scanf("%d%d", &t, &k);
	for (int i = 1; i <= 2000; ++i)
		f[i][i] = 1,
		f[i][1] = i % k;
	for (int i = 1; i <= 2000; ++i)
		for (int j = 2; j <= i - 1; ++j)
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % k;
	for (int i = 1; i <= 2000; ++i)
		for (int j = 1; j <= i; ++j)
			if(!f[i][j]) sa[i][j] = sa[i][j - 1] + 1;
			else sa[i][j] = sa[i][j - 1];
	for (int i = 1; i <= t; ++i) {
		scanf("%d%d", &a, &b);
		ans = 0;
		for (int i = 1; i <= a; ++i)
			ans += sa[i][(i > b ? b : i)];
		printf("%d\n", ans);
	}
	return 0;
}
