#include <bits/stdc++.h>

const long N = 500 + 10;
const long long oo = (int)1e9+7;
using namespace std;
typedef long long LL;
typedef pair<LL,int> ii;

int n, m;
LL a[N][N], f[N][N], d[N][N];

int main()
{   freopen("SIGN.inp","r",stdin);
    freopen("SIGN.out","w",stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    priority_queue <ii,vector<ii>,greater<ii> > qu;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = oo*oo;

    for (int i = 1; i <= n; i++) qu.push(ii(a[1][i],1*N+i)), d[1][i] = a[1][i];

    LL ans = oo*oo;

    while ( !qu.empty() ) {
        LL du, u, v;
        du = qu.top().first;
        u = qu.top().second / N;
        v = qu.top().second % N;
        qu.pop();
        //if ( d[u][v] != du ) continue;
        if ( u == m ) {
            ans = min(ans,du);
            continue;
        }
        if ( d[u+1][v] > du + a[u+1][v] ) {
            d[u+1][v] = du + a[u+1][v];
            qu.push(ii(d[u+1][v],(u+1)*N + v));
        }
        if ( d[u][v-1] > du + a[u][v-1] && v > 1 ) {
            d[u][v-1] = du + a[u][v-1];
            qu.push(ii(d[u][v-1],u*N + v-1));
        }
        if ( d[u][v+1] > du + a[u][v+1] && v < n ) {
            d[u][v+1] = du + a[u][v+1];
            qu.push(ii(d[u][v+1],u*N + v+1));
        }
    }

    cout << ans;
}
