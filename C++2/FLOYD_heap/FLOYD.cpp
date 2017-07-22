#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <vector>
#include <queue>
#include <memory.h>
const long N = 100+10;
const long oo = 1000000000;
using namespace std;
typedef pair<int,int> ii;
int n,m,q;
int d[N], fa[N], ta[N];
vector <ii> a[N];

void inp()
{   freopen("FLOYD.inp","r",stdin);

    scanf("%d %d %d", &n, &m, &q );
    int u,v,k;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d ", &u, &v ,&k);
        a[u].push_back(ii(k,v));
        a[v].push_back(ii(k,u));
    }
    for (int i = 1; i <= n; i++) a[i].push_back(ii(0,0));
}
void init()
{

}
void truyvet(int u, int v)
{   int kq[N],res=0;
    if ( d[v] == oo ) {cout<<0<<'\n'; return; }
    while ( u != v ) {
        kq[++res] = v;
        v = ta[v];
    }
    kq[++res] = u;
    printf("%d ", res);
    while ( res > 0 ) { printf("%d ", kq[res]); --res; }
    printf("\n");
}
void dijkstra(int uu,int vv)
{   priority_queue<ii,vector<ii> > qu;
    for (int i = 1; i <= n; i++) d[i] = oo;
    memset(fa,true,sizeof(fa));
    d[uu] = 0; qu.push(ii(uu,0));
    while ( !qu.empty() ){
        int u,du,uv,v;
            u = qu.top().first;
            du = qu.top().second;
            qu.pop();
            if ( d[u] != du  ) continue;
            for ( int i = 0; i < a[u].size(); i++ ) {
                uv = a[u][i].first;
                v = a[u][i].second;
                if ( d[v] > d[u] + uv ) {
                    d[v] = d[u] + uv;
                    ta[v] = u;
                    qu.push(ii(v,d[v]));
                }
            }
    }
}
void solve()
{   int l,u,v;
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d", &l, &u, &v);
        dijkstra(u,v);
        if ( l == 0 ) printf("%d \n", d[v] );
        else truyvet(u,v);
    }
}
int main()
{   inp();
    solve();
}
