#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;
std::string sky, smg, ans("");
int top, len1(0), len2(0);
int main() {
	std::ios::sync_with_stdio(false);
	std::cin >> sky;
	std::cin >> smg;
	len1 = sky.size(); len2 = smg.size();
	for (int i = 0; i < len2; ++i) {
		int k = toupper(sky[top]) - 'A';
		int l = toupper(smg[i]) - 'A';
		char ch = (l - k + 26) % 26;
		if(isupper(smg[i])) ch += 'A';
		else ch += 'a';
		ans += ch;
		top = (top + 1) % len1;
	}
	std::cout << ans << '\n';
	return 0;
}
