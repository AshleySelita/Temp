#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define re register
const int MAXN = 1e6 + 3;
const int L = 100000;
int n, m, ans, a[MAXN], sub[MAXN], s[MAXN], t[MAXN], k[MAXN];
char buf[L], *pt1, *pt2;
inline char getChar() {
  if (pt1 == pt2) {
    if (feof(stdin)) return '\0';
    pt1 = buf;
    pt2 = buf + fread(buf, 1, L, stdin);
  }
  return *(pt1++);
}
inline int read() {
	int x(0); char c;
	while(!isdigit(c = getChar()));
	do x = x * 10 + (c - '0');
	while(isdigit(c = getChar()));
	return x;
}
inline void print(int x) {
	int sa[11], top(0);
	while(x) {
		sa[++top] = x % 10;
		x /= 10;
	}
	for (re int i = top; i > 0; --i) putchar('0' + sa[i]);
	putchar('\n');
	return ;
}
inline bool judge(int x) {
	int num[MAXN] = {0};
	for (re int i = 1; i < x; i += 2) {
		num[s[i]] += k[i]; num[t[i] + 1] -= k[i];
		num[s[i + 1]] += k[i + 1]; num[t[i + 1] + 1] -= k[i + 1];
	}
	(x & 1) && (num[s[x]] += k[x], num[t[x] + 1] -= k[x]);
	re int sa(0);
	for (re int i = 1; i <= n; ++i) {
		sa += num[i];
		if(sa > a[i]) return 0;
	}
	return 1;
}
int main() {
    n = read(); m = read();
    for (re int i = 1; i < n; i += 2) {
    	a[i] = read(); a[i + 1] = read();
    }
    (n & 1) && (a[n] = read());
    for (re int i = 1; i < m; i += 2) {
    	k[i] = read(); s[i] = read(); t[i] = read();
    	k[i + 1] = read(); s[i + 1] = read(); t[i + 1] = read();
    }
    re int l = 1, r = m, mid = -1;
    while (l <= r) {
    	mid = (l + r) / 2;
    	judge(mid) ? (l = mid + 1, ans = mid) : (r = mid - 1);
    }
    if(ans < m) {
    	putchar('-'); putchar('1'); putchar('\n');
    	print(ans + 1);
    }
    else putchar('0'), putchar('\n');
    return 0;
}
