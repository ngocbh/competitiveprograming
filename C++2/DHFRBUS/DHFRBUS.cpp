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
struct data{
    LL val;
    int p[6];
    void sort1()
    {
        sort(p+1,p+6,greater<int>() );
    }
};
int n, m, k, s, t;
data d[N][6];
vector <ii> a[N];

int main()
{
    //freopen("DHFRBUS.inp","r",stdin);
    //freopen("DHFRBUS.out","w",stdout);

    cin >> n >> m >> k >> s >> t;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].push_back(ii(v,c));
        a[v].push_back(ii(u,c));
    }

    priority_queue <ii,vector<ii>,greater<ii> > qu;

    for (int i = 0; i <= k; i++)
        for (int j = 1; j <= n; j++)
            d[j][i].val = oo*oo;

    for (int i = 0; i <= k; i++) d[s][i].val = 0;

    qu.push(ii(0,s));

    while ( !qu.empty() ) {
        LL du = qu.top().first;
        int u = qu.top().second % N;
        int ku = qu.top().second / N;
        qu.pop();

        if ( d[u][ku].val != du ) continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].first;
            int uv = a[u][i].second;
            if ( d[v][ku].val > du + uv )
            {
                d[v][ku].val = du + uv;
                for (int j = 1; j <= ku; j++) d[v][ku].p[j] = d[u][ku].p[j];
                qu.push(ii(d[v][ku].val, ku*N + v));
            }
            if ( d[v][ku+1].val > du && ku < k )
            {
                d[v][ku+1].val = du;
                for (int j = 1; j <= ku; j++) d[v][ku+1].p[j] = d[u][ku].p[j];
                d[v][ku+1].p[ku+1] = uv;
                d[v][ku+1].sort1();
                qu.push(ii(d[v][ku+1].val, (ku+1)*N + v));
            }
            if ( d[v][k].val > du + d[v][k].p[k] && ku == k )
            {
                d[v][k].val = du + d[v][k].p[k];
                for (int j = 1; j <= k; j++) d[v][k].p[j] = d[u][k].p[j];
                d[v][k].p[k] = uv;
                d[v][k].sort1();
                qu.push(ii(d[v][k].val,k*N + v));
            }
        }
    }

    cout << d[t][k].val;
}
