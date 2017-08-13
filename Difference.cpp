#include <cstdio>
#include <cstring>
int a[100001], n, m, l, r;
int check[100001], sa[100001];
int main() {
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; ++i)
    	scanf("%d", &a[i]), check[i] = sa[a[i]], sa[a[i]] = i;
    for (register int i = 1; i <= m; ++i) {
        bool s = true;
        scanf("%d%d", &l, &r);
        for (register int j = l; j <= r; ++j)
            if(check[j] >= l) {
                s = false;
                printf("No\n"); break;
            }
        if(s) printf("Yes\n");
    }
    return 0;
}
