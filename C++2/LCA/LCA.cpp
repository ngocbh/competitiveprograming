#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int t, n, root;
int dad[N], lv[N], pa[22][N];
int level(int u)
{   int l = 0;
    if ( u == root ) return 1;
    if ( lv[u] != 0 ) return lv[u];
    return lv[u] = level(dad[u]) + 1;
}
int lca(int u,int v)
{
    for (int k = 20; k >= 0; k-- )
            if ( level(pa[k][u]) >= level(v) ) u = pa[k][u];
    for (int k = 20; k >= 0; k-- )
            if ( level(pa[k][v]) >= level(u) ) v = pa[k][v];
    for (int k = 20; k >= 0; k-- )
            if ( pa[k][v] != pa[k][u] )
                u = pa[k][u] , v = pa[k][v];
    while ( u != v ) {
            u = dad[u];
            v = dad[v];
    }
    return u;
}
void inp()
{
    scanf("%d", &n);
    for (int i = 1; i <= N; i++) {
            dad[i] = 0;
            lv[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
            int m,v;
            scanf("%d", &m);
            for (int j = 1; j <= m; j++) {
                    scanf("%d",&v);
                    dad[v] = i;
                    pa[0][v] = i;
            }
    }
    for (int i = 1; i <= n; i++ ) {
            if ( dad[i] == 0 ) root = i;
    }
    pa[0][root] = root; lv[root] = 1;
    for (int k = 1; k <= 20; k++)
        for (int i = 1; i <= n; i++)
            pa[k][i] = pa[k-1][pa[k-1][i]];
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int ans = lca(u,v);
            printf("%d\n", ans);
    }
}
int main()
{  // freopen("LCA.inp","r",stdin);
    cin >> t;
    for (int i = 1; i <= t; i++) {
            printf("Case %d:\n", i);
            inp();
    }

}
