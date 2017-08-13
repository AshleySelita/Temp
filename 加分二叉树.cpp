#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#define re register
typedef long long ll;
std::string ans[31][31], chart[31] = {"0 ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10 ", "11 ",
"12 ", "13 ", "14 ", "15 ", "16 ", "17 ", "18 ", "19 ", "20 ", "21 ", "22 ", "23 ", "24 ", "25 ", "26 ", "27",
"28 ", "29 ", "30 "};
int scr[31][31], n;
inline int read_int() {
	int x(0); char c(0);
	while (!isdigit(c = getchar()));
	do x = x * 10 + (c - '0') ;
	while(isdigit(c = getchar()));
	return x;
}
inline void write_str() {
	int top(0);
	while(ans[1][n][top] != '\0') putchar(ans[1][n][top++]);
	putchar('\n');
	return ;
}
int main() {
	n = read_int();
	for (re int i = 1; i <= n; ++i) scr[i][i] = read_int(), ans[i][i] = chart[i];
	for (re int j = 1; j < n; ++j)
		for (re int i = 1; i <= n - j; ++i) {
			if(scr[i][i + j] < scr[i][i] + scr[i + 1][i + j])
				scr[i][i + j] = scr[i][i] + scr[i + 1][i + j], ans[i][i + j] = ans[i][i] + ans[i + 1][i + j];
			if(scr[i][i + j] < scr[i + j][i + j] + scr[i][i + j - 1])
				scr[i][i + j] = scr[i + j][i + j] + scr[i][i + j - 1], ans[i][i + j] = ans[i + j][i + j] + ans[i][i + j - 1];
			for (re int k = i + 1; k <= i + j - 1; ++k)
				if(scr[i][i + j] < scr[k][k] + scr[i][k - 1] * scr[k + 1][i + j])
					scr[i][i + j] = scr[k][k] + scr[i][k - 1] * scr[k + 1][i + j], ans[i][i + j] = ans[k][k] + ans[i][k - 1] + ans[k + 1][i + j];
		}
	printf("%d\n", scr[1][n]);
	write_str();
	return 0;
}
