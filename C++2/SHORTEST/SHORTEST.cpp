/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <LL,int> ii;

int n, m;
LL d[N];
vector <ii> a[N];

int main()
{
    freopen("SHORTEST.inp","r",stdin);
    freopen("SHORTEST.out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        a[v].push_back(ii(u,c));
    }

    priority_queue<ii,vector<ii>, greater<ii> > qu;
    fill(d,d+N,oo*oo);

    d[n] = 0;
    qu.push(ii(0,n));

    while ( !qu.empty() ) {
        int u = qu.top().second;
        LL du = qu.top().first;
        qu.pop();
        if ( du != d[u] ) continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].first;
            int uv = a[u][i].second;
            if ( d[v] > du + uv ) {
                d[v] = du + uv;
                qu.push(ii(d[v],v));
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if ( d[i] != oo*oo )
            cout << d[i] << endl;
        else
            cout << -1 << endl;
    }
}
