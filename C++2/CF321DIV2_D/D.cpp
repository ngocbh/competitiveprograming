#include <bits/stdc++.h>

const long N = 20;
using namespace std;
typedef long long LL;
int n;
LL a[N], c[N][N], x[N], f[N][N][N];
LL ans = 0;
void ktkq()
{
    LL res = 0, kt = 0;
    for (int i = 1; i <= n; i++) if ( x[i] ) res += a[i], ++kt;
    if ( kt != m ) return;
    int u = 0 v = 0;
    for (int i = 1; i <= n; i++)
        if ( x[i] )
    {
            for (int i = 1; i <= n; i++)
    }
}

void dfs(int i)
{
    if ( i > n ) {
        ktkq();
        return ;
    }
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        dfs(i+1);
    }
}

int main()
{   freopen("D.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) {
        int u,v,cc;
        cin >> u >> v >> cc;
        a[u][v] = cc;
    }
    dfs(1);
}
