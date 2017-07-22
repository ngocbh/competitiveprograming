#include <bits/stdc++.h>

using namespace std;

typedef pair <int,int> ii;
const long N = 1000 + 10;

int n, m, x, y, z, u, v, p, q;
int ca[N], b[N], cb[N][N];
vector <ii> a[N];

int main()
{
    freopen("badmilk.in","r",stdin);
    freopen("badmilk.out","w",stdout);

    cin >> n >> m >> p >> q;
    for (int i = 1; i <= p; i++) {
        cin >> x >> y >> z;
        if ( !cb[y][x] ) ++b[y],cb[y][x] = 1;
        a[x].push_back(ii(y,z));
    }

    for (int i = 1; i <= n; i++) sort(a[i].begin(),a[i].end());

    memset(ca,true,sizeof ca);
    for (int i = 1; i <= q; i++) {
        cin >> u >> v;
        for (int j = 0; j < a[u].size(); j++)
            if ( a[u][j].first != a[u][j-1].first && a[u][j].second >= v ) ca[a[u][j].first] = false;
        for (int i = 1; i <= m; i++) if ( cb[i][u] == 0 ) ca[i] = false;

    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if ( !ca[i] ) continue;
        ans = max(ans,b[i]);
    }

    cout << ans;
}
