#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef pair <int,int> ii;
int m,n,k,u,v,a[N][N],res;
int f[N][N];
ii aa[N];
int main()
{   freopen("BRIDGE.inp","r",stdin);
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= k; i++)
        scanf("%d %d", &aa[i].first, &aa[i].second);
    u = 1; v = 1;
    while ( u != 0 || v != 0 ) {
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }
    aa[k+1].first = m+1; aa[k+1].second = n+1;
    for (int o = 0; o <= k; o++) {
        for (int i = aa[o].first+1; i < aa[o+1].first; i++)
            for (int j = aa[o].second+1; j < aa[o+1].second; j++) {
                    f[i][j] = max( f[i-1][j],f[i][j-1] );
                    if ( a[i][j] ) f[i][j] = max(f[i][j], f[i-1][j-1] +1);
            }
            res += f[aa[o+1].first-1][aa[o+1].second-1];
    }
    cout<<res;

}
