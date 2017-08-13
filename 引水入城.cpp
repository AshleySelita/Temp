#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
struct range {
	int l, r;
	range() { l = 0x7ffffff, r = -0x7ffffff; }
}a[501];
int n, m, map[501][501], ans, cnt;
int dx[] = {0, 0, 1, 0, -1},
	dy[] = {0, 1, 0, -1, 0};
int vis[501][501];
bool _ans[501];
void search(int x, int y, int clr) {
	if(x == n) {
		if(!_ans[y]) --ans, _ans[y] = 1;
		a[clr].l = std::min(a[clr].l, y);
		a[clr].r = std::max(a[clr].r, y);
	}
	for (int i = 1; i <= 4; ++i) {
		int mx = x + dx[i], my = y + dy[i];
		if(mx >= 1 && mx <= n && my >= 1 && my <= m && vis[mx][my] != clr && map[x][y] > map[mx][my]) {
			vis[mx][my] = clr; search(mx, my, clr);
		}
	}
}
inline int read() {
	int x(0); char c(0);
	while (!isdigit(c = getchar()));
	do x = x * 10 + (c - '0'); while (isdigit(c = getchar()));
	return x;
}
inline bool cmp(range a, range b) {
	if(a.l == b.l)
		return a.r < b.r;
	else return a.l < b.l;
}
int main() {
	n = read(); m = read();
	ans = m;
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			map[i][j] = read();
	for (register int i = 1; i <= m; ++i) 
		if(map[1][i] >= map[1][i - 1] && map[1][i] >= map[1][i + 1]){
			vis[1][i] = i, search(1, i, i);
		}
	if(!ans) {
		std::sort(a + 1, a + m + 1, cmp);
		register int top = m, tot = 0;
		while(a[top].l == 0x7ffffff) top--;
		while(tot < m) {
			int sa = tot;
			for (int i = 1; i <= top; ++i)
				if(a[i].l <= tot + 1)
					sa = std::max(sa, a[i].r);
			cnt++;
			tot = sa;
		}
		printf("1\n%d\n", cnt);
	}
	else printf("0\n%d\n", ans);
	return 0;
}
