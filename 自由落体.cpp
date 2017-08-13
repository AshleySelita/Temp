#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
typedef long long ll;
typedef double ldb;
const ldb CHK = 1e-4;
ldb h, s1, v, l, k, ans(0);
int n;
int main() {
	scanf("%lf%lf%lf%lf%lf%d", &h, &s1, &v, &l, &k, &n);
	ldb time = sqrt((h - CHK) / 5);
	ldb dis = s1 - v * time;
	int ls = ceil(dis - CHK);
	if(ls - (n - 1) > CHK) {
		printf("0\n"); return 0;
	}
	if(ls < 0) ls = 0;
	time = sqrt((h - k - CHK) / 5);
	dis = s1 - v * time;
	int rs = floor(dis + l + CHK);
	if(rs - (n - 1) > CHK) rs = n - 1;
	printf("%d", rs - ls + 1);
	return 0;
}
