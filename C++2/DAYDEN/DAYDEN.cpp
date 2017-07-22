#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;

int n, k, m, ans;
int cnt[N], a[N], f[N];

void solve(int x)
{
        for (int i = 1; i*x <= n; i++) {
                f[i*x] = 1 - f[i*x];
        }
}

int main()
{   freopen("DAYDEN.inp","r",stdin);
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
            f[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ++cnt[a[i]];
    }

    for (int i = 1; i <= k; i++)
            if ( cnt[i] % 2 == 1 ) {
                    solve(i);
            }
    for (int i = 1; i <= n; i++)
            ans += ( f[i] == 1 );
    printf("%d", ans );
}
