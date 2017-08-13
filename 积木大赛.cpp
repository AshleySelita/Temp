#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
const int MAXN = 100010;
typedef long long ll;
int f[MAXN], a[MAXN], n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	f[1] = a[1];
	for (int i = 2; i <= n; ++i)
		if(a[i] > a[i - 1])
			f[i] = f[i - 1] + (a[i] - a[i - 1]);
		else f[i] = f[i - 1];
	printf("%d\n", f[n]);
	return 0;
}
