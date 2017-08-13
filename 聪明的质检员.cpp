#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
const int MAXN = 200001;
struct range {
	ll l, r;
}a[MAXN];
ll n, m, s, w[MAXN], v[MAXN], sn[MAXN], sv[MAXN];
ll left, right;
inline ll read() {
	ll x(0); char c(0);
	while (!isdigit(c = getchar()));
	do x = x * 10 + (c - '0');
	while (isdigit(c = getchar()));
	return x;
}
inline void init(ll x) {
	for (int i = 1; i <= n; ++i)
		if(w[i] >= x) sn[i] = sn[i - 1] + 1, sv[i] = sv[i - 1] + v[i];
		else sn[i] = sn[i - 1], sv[i] = sv[i - 1];
}
inline ll check(ll mid) {
	init(mid);
	ll ans(0);
	for (int i = 1; i <= m; ++i)
		ans += (sn[a[i].r] - sn[a[i].l - 1]) * (sv[a[i].r] - sv[a[i].l - 1]);
	return ans;	
}
int main() {
	n = read(); m = read(); s = read();
	for (int i = 1; i <= n; ++i)
		w[i] = read(), v[i] = read(), right = std::max(right, w[i]);
	for (int i = 1; i <= m; ++i)
		a[i].l = read(), a[i].r = read();
	right++;
	ll ans = 0x7ffffffffffff;
	while (left <= right) {
		ll mid = (left + right) >> 1;
		ll tmp = check(mid);
		if(tmp > s) left = mid + 1;
		if(tmp < s) right = mid - 1;
		if(tmp == s) {
			printf("0\n"); return 0;
		}
		ll sa = std::abs(s - tmp);
		ans = std::min(ans, sa);
	}
	printf("%lld\n", ans);
}
