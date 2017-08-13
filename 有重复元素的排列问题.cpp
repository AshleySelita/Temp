#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
char a[501];
int num[26], n, ans;
inline void print() {
	printf("%s", a);
	putchar('\n');
	ans++;
	return ;
}
void solve(int now) {
	if(now == n) {
		print(); return ;
	}
	for (int i = 0; i < 26; ++i)
		if(num[i]) {
			num[i]--;
			a[now] = i + 'a';
			solve(now + 1);
			num[i]++;
		}
}
int main() {
	scanf("%d\n", &n);
	char c(0);
	while(isalpha(c = getchar())) {
		num[c - 'a']++;
	}
	solve(0);
	printf("%d\n", ans);
	return 0;
}
