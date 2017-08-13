#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
const int MAXN = 100001;
typedef long long ll;
std::string ss[MAXN];
bool sts[MAXN], tmp;
int n, m, pnt(0), num;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> sts[i] >> ss[i]; 
	}
	for (int i = 1; i <= m; ++i) {
		std::cin >> tmp >> num;
		if(!tmp) {
			if(sts[pnt]) {
				pnt = (pnt + num) % n;
			}
			else {
				pnt = ((pnt - num) % n + n) % n; 
			}
		}
		else {
			if(sts[pnt]) {
				pnt = ((pnt - num) % n + n) % n;
			}
			else {
				pnt = (pnt + num) % n;
			}
		}
	}
	std::cout << ss[pnt] << '\n';
	return 0;
}
