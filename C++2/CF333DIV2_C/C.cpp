/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 500;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m;
int a[N][N], d[N];

void dijkstra(int x)
{
    priority_queue <ii,vector<ii>,greater<ii> > qu;
    fill(d,d+N,oo);

    qu.push(ii(0,1));
    d[1] = 0;

    while ( !qu.empty() ) {
        int u = qu.top().second;
        int du = qu.top().first;
        qu.pop();
        if ( du != d[u] ) continue;

        for (int v = 1; v <= n; v++) {
            if ( a[u][v] == x && u != v ) {
                if ( d[v] > d[u] + 1 ) {
                    d[v] = d[u] + 1;
                    qu.push(ii(d[v],v));
                }
            }
        }
    }

    if ( d[n] != oo )
        cout << d[n];
    else
        cout << -1;
}

int main()
{
    //freopen("C.inp","r",stdin);
    //freopen(".out","w",stdout);

    ios::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    dijkstra(1-a[1][n]);
}
