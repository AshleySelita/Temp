#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
const int MAXN = 1001;
struct station{
	int num, maxn, tm, range;
}a[MAXN];
struct passenger{
	int l, r, t;
}b[MAXN * 10];
int n, m, k, d[MAXN], ans(0);
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i < n; ++i) scanf("%d", &d[i]);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &b[i].t, &b[i].l, &b[i].r);
		a[b[i].r].num += 1;
		a[b[i].l].maxn = std::max(a[b[i].l].maxn, b[i].t);
	}
	for (int i = 1; i <= n; ++i) a[i].num += a[i - 1].num;
	for (int i = 2; i <= n; ++i) a[i].tm = std::max(a[i - 1].maxn, a[i - 1].tm) + d[i - 1];
	for (int i = 1; i <= m; ++i) ans += a[b[i].r].tm - b[i].t;
	for (int i = k; i >= 1; --i) {
		a[n].range = n; a[n - 1].range = n;
		for (int j = n - 2; j >= 1; --j)
			if(a[j + 1].tm <= a[j + 1].maxn) a[j].range = j + 1;
			else a[j].range = a[j + 1].range;
		int sa(0), id;
		for (int j = 1; j <= n; ++j)
			if(a[a[j].range].num - a[j].num > sa && d[j] > 0)
				sa = a[a[j].range].num - a[j].num, id = j;
		d[id]--; ans -= sa;
		for (int j = 2; j <= n; ++j) a[j].tm = std::max(a[j - 1].maxn, a[j - 1].tm) + d[j - 1];
	}
	printf("%d\n", ans);
	return 0;
}
