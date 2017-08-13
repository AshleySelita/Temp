#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#define re register
typedef long long ll;
const ll MOD = 10007;
ll a, b, k, n, m;
inline ll fast_pow(ll x, ll num) {
	ll sum(1), tot(x);
	while(num) {
		if(num & 1) sum = (sum * tot) % MOD;
		tot = (tot * tot) % MOD;
		num >>= 1;
	}
	return sum;
}
inline ll Comb(ll n, ll m) {
	ll ans(1);
	for (ll i = 1; i <= m; ++i)
		ans = ((ans * (n - i + 1) % MOD) * fast_pow(i , MOD - 2)) % MOD;
	return ans;
}
int main() {
	scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m);
	a %= MOD; b %= MOD;
	ll coea = fast_pow(a, n);
	ll coey = fast_pow(b, m);
	ll coeC = Comb(k, m);
	ll ans = (((coea * coey) % MOD) * coeC) % MOD;
	printf("%lld\n", ans);
	return 0; 
}
