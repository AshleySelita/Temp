#include <algorithm>
#include <cstdio>
struct dot{
	int x, y;
}a[51];
struct matrix{
	int lx, ly, rx, ry;
	bool fl;
}m[5];
int n, k, ans(0x7fffffff);
typedef matrix mtx;
inline bool is_in_it(mtx tmp, int x, int y) {
	if(x >= tmp.lx && x <= tmp.rx && y >= tmp.ly && y <= tmp.ry) return true;
	return false;
}
inline bool check(mtx mt_n, mtx dt_n) {
	if(is_in_it(mt_n, dt_n.lx, dt_n.ly)) return true;
	if(is_in_it(mt_n, dt_n.lx, dt_n.ry)) return true;
	if(is_in_it(mt_n, dt_n.rx, dt_n.ly)) return true;
	if(is_in_it(mt_n, dt_n.rx, dt_n.ry)) return true;
	return false;
}
inline void dfs(int now) {
	int sa(0);
	for (int i = 1; i <= k; ++i) {
		if(m[i].fl) {
			for (int j = i + 1; j <= k; ++j) 
				if(check(m[i], m[j])) return ;
		}
		sa += (m[i].rx - m[i].lx) * (m[i].ry - m[i].ly);
	}
	if(sa >= ans) return ;
	if(now > n) {
		ans = sa;
		return ;
	}
	for (int i = 1; i <= k; ++i) {
		matrix tmp = m[i];
		if(!m[i].fl) {
			m[i].fl = 1;
			m[i].lx = m[i].rx = a[now].x;
			m[i].ly = m[i].ry = a[now].y;
			dfs(now + 1);
			m[i] = tmp;
		}
		else {
			m[i].lx = std::min(m[i].lx, a[now].x);
			m[i].rx = std::max(m[i].rx, a[now].x);
			m[i].ly = std::min(m[i].ly, a[now].y);
			m[i].ry = std::max(m[i].ry, a[now].y);
			dfs(now + 1);
			m[i] = tmp;
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].x, &a[i].y);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
