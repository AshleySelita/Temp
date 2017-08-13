#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
int m, n;
int que[401], num[21][21], time[21][21], ans(0);
int cnt[21], last[21];
bool ch[21][2001];
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n * m; ++i)
		scanf("%d", &que[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &num[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &time[i][j]);
	int tmp = n * m;
	for (int i = 1; i <= tmp; ++i) {
		cnt[que[i]]++;
		int tmpj = que[i], tmpc = cnt[que[i]];
		int tmpn = num[tmpj][tmpc];
 		for (int j = last[tmpj]; ; ++j) {
			bool fl = true;
			int tmpt = j + time[tmpj][tmpc];
			for (int k = j + 1; k <= tmpt; ++k)
				if(ch[tmpn][k]) {
					fl = 0; break;
				}
			if(fl) {
				for (int k = j + 1; k <= tmpt; ++k)
					ch[tmpn][k] = true;
				last[tmpj] = std::max(last[tmpj], tmpt);
				ans = std::max(last[tmpj], ans);
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
