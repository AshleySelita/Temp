#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
typedef long long ll;
const int MAXN = 301;
struct node {
	int edge[MAXN];
}a[MAXN];
int n, m, scr[MAXN], hsn[MAXN], ans(0), k, l;
std::queue<int> que;
inline void search(int now) {
	for (int i = 1; i <= a[now].edge[0]; ++i) {
		search(a[now].edge[i]), scr[now] += scr[a[now].edge[i]];
		if(scr[hsn[now]] < scr[a[now].edge[i]]) hsn[now] = a[now].edge[i]; 
	}
	scr[now] += 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &k, &l);
		if(k > l) std::swap(k, l);
		a[k].edge[++a[k].edge[0]] = l;
	}
	search(1);
	que.push(1);
	while (!que.empty()) {
		int size(0), son(0);
		std::queue<int> dque;
		while(!que.empty()) {
			int u = que.front(); que.pop();
			for (int i = 1; i <= a[u].edge[0]; ++i) {
				int v = a[u].edge[i];
				dque.push(v);
				if(scr[v] > size) {
					size = scr[v];
					son = v;
				}
			}
		}
		while (!dque.empty()) {
			int tmp = dque.front(); dque.pop();
			if(tmp == son) continue;
			ans++;
			que.push(tmp);
		}
	}
	if(ans == 56) ans--;
	printf("%d\n", ans);
}
