#include <bits/stdc++.h>

const long N = 10000 + 10;
const long oo = 1000000000 + 10;
using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;
int n, m, k, s1, s2, t;
LL a[N][N], cu[N], cv[N], l[N], r[N], x[N], ans[N];
string res;
bool ok = false;
LL dijkstra(int s,int t)
{
    priority_queue <ii,vector<ii>,greater<ii> > qu;
    LL d[N];
    for (int i = 1; i <= n; i++ ) d[i] = oo*oo;
    d[s] = 0;
    qu.push(ii(s,0));
    while ( !qu.empty() ) {
            LL u,v,uv,du;
            u = qu.top().first;
            du = qu.top().second;
            qu.pop();
            if ( d[u] != du ) continue;
            for (int i = 1; i <= n; i++) {
                if ( a[u][i] == 0 ) continue;
                if ( d[i] > d[u] + a[u][i] ) {
                        d[i] = d[u] + a[u][i];
                        qu.push(ii(i,d[i]));
                }
            }
    }
    return d[t];
}
void tryans()
{
    for (int i = 1; i <= k; i++) {
            if ( x[i] == 0 ) {
                    a[cu[i]][cv[i]] = l[i];
            } else {
                    a[cu[i]][cv[i]] = r[i];
            }
    }
    LL res1, res2;
    res1 = dijkstra(s1,t);
    res2 = dijkstra(s2,t);
    if ( res1 < res2 ) {
           for (int i = 1; i <= k; i++) {
            if ( x[i] == 0 ) {
                    ans[i] = l[i];
            } else {
                    ans[i] = r[i];
            }
           }
           res = "WIN";
           ok = true;
           return;
    }
    if ( res1 == res2 ) {
            for (int i = 1; i <= k; i++) {
            if ( x[i] == 0 ) {
                    ans[i] = l[i];
            } else {
                    ans[i] = r[i];
            }

           }
           res = "DRAW";
    }
}
void duyet(int i)
{       if (ok) return;
        if ( i > k ) { tryans(); return; }
        for (int j = 0; j <= 1; j++) {
                x[i] =  j;
                duyet(i+1);
        }
}
int main()
{
        freopen("HACK.inp","r",stdin);
        freopen("HACK.out","w",stdout);
        cin >> n >> m >> k;
        cin >> s1 >> s2 >> t;
        for (int i = 1; i <= m; i++) {
                int u , v, c;
                cin >> u >>  v >> c;
                a[u][v] = c;
        }
        for  (int  i = 1; i <= k; i++ ) {
                cin >> cu[i] >> cv[i] >> l[i] >> r[i];
        }
        duyet(1);
        if ( res != "" ) {
                cout << res << endl;
                for (int i = 1; i <= k; i++) cout << ans[i] << " ";
                return 0;
        }
        cout << "LOSE" << endl;
}
