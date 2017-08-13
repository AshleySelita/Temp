#include <cstdio>
#include <algorithm>
#include <cstring>
const int MXLNTH = 10010;
struct ser{ int l, r; } a[10100];
int n, l1, r1, minn[MXLNTH], mul[MXLNTH], dive[MXLNTH], tmp[MXLNTH];
inline bool cmp(ser x, ser y) {return x.l*x.r < y.l*y.r;}
inline void multiply(int che) {
	int sa[MXLNTH] = {0}, x(0);
	sa[0] = mul[0];
	for (int i = MXLNTH - 1, j = mul[0]; (i >= 1) && (j >= 1); --i, --j)
		sa[i] = mul[j];
	for (int i = MXLNTH - 1; i >= 1; --i) {
		sa[i] *= che;
		sa[i] += x;
		x = sa[i] / 10;
		sa[i] %= 10;
	}
	int len(1);
	while (!sa[len]) len++;
	mul[0] = (MXLNTH - 1) - len + 1;
	for (int i = 1; i <= mul[0]; ++i)
		mul[i] = sa[(MXLNTH - 1) - mul[0] + i];
	return ;
}
inline void divide(int chu) {
	memset(dive, 0, sizeof dive);
	memset(tmp, 0, sizeof tmp);
	int k(0);
	for (int i = 1; i <= mul[0]; ++i){
		tmp[i] = (k * 10 + mul[i]) / chu;
		k = (k * 10 + mul[i]) % chu;
	}
	int len(1);
	while(!tmp[len]) len++;
	for (int i = len, j = 1; i < MXLNTH; ++i, ++j)
		dive[j] = tmp[i];
	dive[0] = mul[0] - len + 1;
	if(!dive[0]) dive[0] = 1;
	return ;
}
inline bool compare() {
	if(minn[0] != dive[0]) return minn[0] < dive[0];
	else for (int i = 1; i <= minn[0]; ++i) if(minn[i] != dive[i]) return minn[i] < dive[i];
	return false;
}
inline void doit() {
	for (int i = 0; i < MXLNTH; ++i)
		minn[i] = dive[i];
	return ;
}
inline void print() {
	for (int i = 1; i <= minn[0]; ++i)
		printf("%d", minn[i]);
	printf("\n");
	return ;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) scanf("%d%d", &a[i].l, &a[i].r);
	std::sort(a+1, a+1+n, cmp);
	mul[0] = 1; mul[1] = 1;
	for (int i = 0; i <= n; ++i) {
		if(i > 0) divide(a[i].r);
		else dive[0] = 1;
		multiply(a[i].l);
		if(compare()) doit();
	}
	print();
	return 0;
}
