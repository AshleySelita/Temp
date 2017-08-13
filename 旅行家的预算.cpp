#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
const int MAXN = 100001;
double d1, c, d2, pp, oil, cost, need, now;
double dis[MAXN], p[MAXN], box[MAXN][2];
int n, l(1), r(1);
int main() {
	scanf("%lf%lf%lf%lf%d", &d1, &c, &d2, &pp, &n);
	for (int i = 1; i <= n; ++i) scanf("%lf%lf", &dis[i], &p[i]);
	dis[n + 1] = d1; p[0] = pp;
	if(n == 0) {
		if(double(d1 / d2) > c) {
			printf("No Solution\n");
			return 0;
		}
		printf("%.2lf\n", (d1 / d2) * pp);
		return 0;
	}
	box[l][0] = pp; box[l][1] = c;
	for (int i = 1; i <= n + 1; ++i) {
		need = (dis[i] - dis[i - 1]) / d2;
		if(need > c) {
			printf("No Solution\n");
			return 0;
		}
		oil = need;
		while (need > 0) {
			if(box[l][1] < need) {
				need -= box[l][1];
				cost += box[l][1] * box[l][0];
				l++;
			}
			else {
				cost += need * box[l][0];
				box[l][1] -= need;
				break;
			}
			if(l > r) {
				printf("No Solution\n");
				return 0;
			}
		}
		if (i == n + 1) {
			printf("%.2lf", cost);
			return 0;
		}
		while (l <= r && box[r][0] > p[i]) {
			oil += box[r][1];
			r--;
		}
		r++;
		box[r][1] = oil; box[r][0] = p[i];
	}
	return 0;
}
