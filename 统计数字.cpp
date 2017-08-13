#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
typedef long long ll;
std::map<ll, int> ma;
int top(0);
ll num[10001];
inline ll read() {
	ll x(0); char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = getchar();
	return x;
}
int main () {
	int n;
	ll a;
	n = read();
	for (int i = 1; i <= n; ++i) {
		a = read();
		if(!ma[a]) num[++top] = a;
		ma[a]++;
	}
	std::sort(num + 1, num + top + 1);
	for (int i = 1; i <= top; ++i)
		printf("%lld %d\n", num[i], ma[num[i]]);
	return 0;
}
