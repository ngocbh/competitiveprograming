/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>
#define mp(a,b,c) iii(a,ii(b,c))
#define pb push_back
#define cin fi
#define cout fo

const long N = 500 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
ifstream fi("CITIES.inp");
ofstream fo("CITIES.out");

typedef long long LL;
typedef pair <LL,LL> ii;
typedef pair <LL,ii> iii;

LL n, m;
iii M[1000010];
LL ca[N];
LL c[N][N];
vector <LL> a[N];

LL dfs(LL u)
{
    LL c = 1;
    ca[u] = 2;
    for (int i = 0; i < a[u].size(); i++) {
        LL v = a[u][i];
        if ( ca[v] != 1 ) continue;
        c += dfs(v);
    }
    return c;
}

int main()
{
    //freopen("CITIES.inp","r",stdin);
    //freopen("CITIES.out","w",stdout);

    cin >> n >> m;
    while ( n != 0 || m != 0 ) {
        LL _max = -oo;
        for (LL i = 1; i <= m; i++) {
            LL u, v, uv;
            cin >> u >> v >> uv;
            M[i] = mp(uv,u,v);
            _max = max(_max,1LL*uv);
        }

        memset(c,0,sizeof c);
        for (int i = 1; i <= n; i++) a[i].clear();

        for (int i = 1; i <= m; i++) {
            LL uv = M[i].first;
            LL u = M[i].second.first;
            LL v = M[i].second.second;

            if ( uv != _max ) continue;

            c[u][v] = c[v][u] = uv;
            a[u].push_back(v);
            a[v].push_back(u);
            ca[u] = ca[v] = 1;
        }

        LL ans = 0;

        for (LL i = 1; i <= n; i++) {
            if ( ca[i] == 1 ) {
                ans = max(dfs(i),ans);
            }
        }

        cout << ans << endl;

        n = m = 0;
        cin >> n >> m;
    }

}
