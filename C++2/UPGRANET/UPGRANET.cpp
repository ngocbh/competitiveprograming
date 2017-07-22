/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

struct data{
    int u, v, c;
};
int n,m;
LL ans;
int a[N][N], d[N],pa[N];
data M[N*N];

bool cmp(data A, data B)
{
    return A.c < B.c;
}

void solve(int s,int t,int cx)
{
    a[s][t] = 0;
    a[t][s] = 0;

    priority_queue <ii> qu;
    memset(pa,0,sizeof pa);
    qu.push(ii(oo,s));
    fill(d,d+N,0);
    d[s] = 0;

    while ( !qu.empty() ) {
        int u = qu.top().second;
        int du = qu.top().first;
        qu.pop();

        if ( u == t ) continue;

        for (int v = 1; v <= n; v++) {
            if ( !a[u][v] || u == v || v == pa[u] ) continue;
            if ( d[v] < min(du,a[u][v]) ) {
                d[v] = min(du,a[u][v]);
                pa[v] = u;
                qu.push(ii(d[v],v));
            }
        }
    }

    if ( d[t] > cx && d[t] != oo ) {
        ans += d[t] - cx;
        a[s][t] = d[t];
        a[t][s] = d[t];
    }
}

int main()
{
    //freopen("UPGRANET.inp","r",stdin);
    //freopen("UPGRANET.out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u][v] = c;
        a[v][u] = c;
        M[i] = data{u,v,c};
    }

    sort(M+1,M+m+1,cmp);

    for (int i = 1; i <= m; i++) {
        int u = M[i].u;
        int v = M[i].v;
        int c = M[i].c;
        solve(u,v,c);
    }

    cout << ans;
}
