/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 255;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, k;
int ca[N], d[N][N], c[N], f[N][N], cs[N];
vector <ii> a[N];

bool cmp(int i,int j)
{
    return c[i] < c[j];
}

void floyd()
{
    sort(cs+1,cs+n+1,cmp);
    for (int i = 1; i <= n; i++) {
        int k = cs[i];
        for (int ui = 1; ui <= n; ui++)
            for (int vi = 1; vi <= n; vi++) {
                    int u = cs[ui];
                    int v = cs[vi];
                    if ( f[u][v] > f[u][k] + f[k][v] ) {
                        f[u][v] = f[u][k] + f[k][v];
                        if ( d[u][v] > f[u][v] + max(c[u],max(c[v],c[k])) ) {
                            d[u][v] = f[u][v] + max(c[u],max(c[v],c[k]));
                        }
                    }

            }
    }
}

int main()
{
    freopen("TOLL.inp","r",stdin);
    //freopen("TOLL.out","w",stdout);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( i != j )
                d[i][j] = f[i][j] = oo;

    for (int i = 1; i <= n; i++) cin >> c[i], cs[i] = i;
    for (int i = 1; i <= m; i++) {
        int u , v , uv;
        cin >> u >> v >> uv;
        f[u][v] = min(f[u][v],uv); d[u][v] = min(d[u][v] , uv + max(c[u],c[v]) );
        f[v][u] = min(f[v][u],uv); d[v][u] = d[u][v];
    }

    floyd();

    for (int i = 1; i <= k; i++) {
        int s, t;
        cin >> s >> t;
        cout << d[s][t] << endl;
    }
}
