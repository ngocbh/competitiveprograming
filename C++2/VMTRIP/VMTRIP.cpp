#include <bits/stdc++.h>

const long N = 100000 + 10;
const long oo = 1000000000 + 7;
const long M = 1000000;
using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;
struct data{
    int u, du, x;
};

int n, m, k, s, t;
LL ca[N], d1[N], dn[N], p[N],x[N], f[N], ta[N], res[N];

vector <int> a[N];

void bfs(LL s,LL d[])
{
    memset(ca,true,sizeof(ca));
    for (int i = 1; i <= n; i++) d[i] = oo;
    queue <ii> qu;
    qu.push(ii(s,0));
    ca[s] = false;
    d[s] = 0;
    while ( !qu.empty() ) {
        int u,v,du;
        u = qu.front().first;
        du = qu.front().second;
        qu.pop();

        if ( !k && u == n ) k = du;

        for (int i = 0; i < a[u].size(); i++) {
            v = a[u][i];
            if ( ca[v] && d[v] > du + 1 ) {
                ca[v] = false;
                d[v] = d[u] + 1;
                qu.push(ii(v,d[v]));
            }
        }
    }
}

int main()
{   freopen("VMTRIP.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    bfs(1,d1);
    bfs(n,dn);
    k;

    for (int i = 1; i <= k+1; i++) cin >> x[i];
    for (int i = 1; i <= k+1; i++) p[x[i]] = (k+2-i)*M;

    queue <data> qu;
    memset(ca,true,sizeof(ca));
    qu.push(data{1,1,0});
    ca[s] = false;

    while ( !qu.empty() ) {
        int u, du , v;
        LL x;
        u = qu.front().u;
        du = qu.front().du;
        x = qu.front().x;
        qu.pop();

        for (int i = 0; i < a[u].size(); i++) {
                v = a[u][i];
                if ( !ca[v] ) {
                        if ( d1[v] + dn[v] == k && du == d1[v] && f[v] < max(x,p[du]+n-u) ) {
                            f[v] = max(x,p[u]+n-u);
                            ta[v] = u;
                        }
                        continue;
                }

                if ( d1[v] + dn[v] == k ) {
                    qu.push(data{v,du+1,max(x,p[du]+n-u)});
                    ca[v] = false;
                    ta[v] = u;
                    f[v] = max(x,p[du]+n-u);
                }
        }
    }

    int u = n, ans = 0;
    while ( u != 1 ) {
        res[++ans] = u;
        u = ta[u];
    }
    res[++ans] = 1;
    for (int i = ans; i > 0; i--) cout << res[i] << " ";
}
