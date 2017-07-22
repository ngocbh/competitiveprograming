#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
const long N = 100+10;
using namespace std;

int n ,m ,q ,c[N][N] ,d[N] ,ta[N], fa[N];


void inp()
{
    //freopen("FLOYD.inp","r",stdin);
        //freopen("FLOYD.out","w",stdout);

        scanf("%d %d %d", &n, &m, &q );
        int u,v,t;
        for (int i = 1; i <= m; i++){
                scanf("%d %d %d", &u, &v, &t);
                c[u][v] = t ;
                c[v][u] = t ;
        }
}
void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = 100000000 ;
}
void floyd()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++ )
            for (int k = 1; k <= n; k++ )
                c[i][j] = min( c[i][k] + c[k][j] , c[i][j] );
}
void dijkstra(int uu,int vv)
{
    for (int i=1; i<=n; i++) d[i] = 1000000000;
    memset(fa,true,sizeof(fa));
    d[uu] = 0;
    while ( true) {
            int min1=1000000000,u=0;
            for (int i=1; i<=n; i++)
                if ( d[i] < min1 && fa[i] ) {
                    min1 = d[i];
                    u = i;
                }
            if ( u == 0 ) break;
            fa[u] = false;
            for (int v=1; v<=n; v++)
                if ( d[v] > d[u] + c[u][v] && fa[v] && c[u][v] ) {
                    d[v] = d[u] + c[u][v];
                    ta[v] = u;
                }
    }
}
void truyvet(int u,int v)
{   int kq[N],res=0;
    if ( d[v] == 1000000000 ) { cout<<0; return; }
    while ( v != u ){
        kq[++res] = v;
        v = ta[v];
    }
    kq[++res] = u;
    printf("%d ", res);
    for (int i = res; i>0 ; i--) printf("%d ", kq[i]);
    printf("\n");
}
void solve()
{   //floyd();
    int l, u, v;
    for (int i = 1; i <= q; i++){
            scanf("%d %d %d", &l, &u, &v);
            dijkstra(u,v);
            if ( l == 0 )
                printf("%d \n", d[v]);
            else
                truyvet(u,v);
    }
}
int main()
{
        //init();
        inp();
        solve();

}
