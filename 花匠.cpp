#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
const int MAXN = 100001;
int n, h[MAXN], ans(1);
bool sta(0);
int main(int argc, char **argv) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
	if(h[2] >= h[1]) sta = 1;
	for(int i = 1; i < n; ++i) {
		if(sta) if(h[i + 1] < h[i]) {
			ans++; sta = false; continue;
		}
		if(!sta) if(h[i + 1] > h[i]) {
			ans++; sta = true; continue;
		}
	}
	printf("%d\n", ans+1);
	return 0;
}
