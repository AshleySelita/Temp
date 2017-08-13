#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
typedef long long ll;
int status[6][6] = {{0, 0, 0, 0, 0, 0},
					{0, 2, 0, 1, 1, 0},
					{0, 1, 2, 0, 1, 0},
					{0, 0, 1, 2, 0, 1},
					{0, 0, 0, 1, 2, 1},
					{0, 1, 1, 0, 0, 2}};
int seqa[201], seqb[201];
int topa(0), topb(0), n, numa, numb, lena, lenb;
int main() {
	scanf("%d%d%d", &n, &lena, &lenb);
	for (int i = 0; i < lena; ++i) scanf("%d", &seqa[i]), seqa[i] += 1;
	for (int i = 0; i < lenb; ++i) scanf("%d", &seqb[i]), seqb[i] += 1;
	for (int i = 1; i <= n; ++i) {
		int tmp = status[seqa[topa]][seqb[topb]];
		if(!tmp) numb++;
		else if(tmp == 1) numa++;
		topa = (topa + 1) % lena;
		topb = (topb + 1) % lenb; 
	}
	printf("%d %d\n", numa, numb);
	return 0;
}
