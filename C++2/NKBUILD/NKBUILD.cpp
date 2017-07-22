/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100 + 10;
const long long  oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;


int n, m, k, SUM = 0;
LL ans;
int ca[N], p[N], h[N];
LL a[N][N], d[N][N];

void dfs(int u,int c,LL x)
{
    ca[u] = false;

    if ( c == SUM ) {
        ans = min(ans,x);
    }
    for (int v = 1; v <= n; v++) {
        int du = a[u][v];
        if ( a[u][v] == oo*oo ) continue;
        if ( !ca[v] ) continue;


    }
}

int main()
{   freopen("NKBUILD.inp","r",stdin);
    //freopen("NKBUILD.out","w",stdout);
    cin >> n >> m >> k;

    int muti = 1;
    for (int i = 1; i <= n; i++) h[i] = 0;

    for (int i = 1; i <= k; i++) {
        cin >> p[i];
        h[p[i]] = (1<<i);
        SUM |= h[p[i]];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( i != j ) {
                a[i][j] = oo*oo;
            }

    for (int i = 1; i <= m; i++) {
        LL u, v, c;
        cin >> u >> v >> c;
        a[u][v] = min(a[u][v],c);
        a[v][u] = min(a[v][u],c);
    }

    ans = oo*oo;
    memset(ca,true,sizeof ca);

    dfs(p[1],h[p[1]],0);
    cout << ans;
}

