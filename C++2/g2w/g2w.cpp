#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#define maxn 10000+100
#define maxm 100000+100
#define oo 10000000000+19

using namespace std;
typedef pair <int,int> ii;
int b[maxn],c[maxn],m,n,p,q,d[maxn],fe[maxn],ca[maxn],ta[maxn];
vector <ii> a[maxn];
void nhap()
{
    freopen("g2w.inp","r",stdin);
    freopen("g2w.out","w",stdout);
    scanf("%d %d %d %d" ,&n ,&m ,&p, &q );
    for (int i=1; i<=p; i++) scanf("%d", &b[i]);
    for (int i=1; i<=q; i++) scanf("%d", &c[i]);
    for (int i=1; i<=m; i++) {
        int u,v,k;
        scanf("%d %d %d", &u, &v, &k);
        a[u].push_back( ii(k,v) );
    }
    for (int i=1; i<=n; i++) a[i].push_back( ii(0,0) );
    ///===========nhap();
}
void dijkstra(int x,int y)
{  priority_queue <ii, vector <ii>, greater<ii> > qu;
   int i,u,v,du,uv;
   for (int i=1; i<=n; i++) d[i]=oo;
   d[x]=0;
   qu.push(ii(0,x));

    while (qu.size()){
         u=qu.top().second;
         du=qu.top().first;
         qu.pop();
         if (!ca[u]) continue;
         if ( du!=d[u] ) continue;
         for (int i = 0; v = a[u][i].second; i++)
         if (ca[v])
         {
                uv = a[u][i].first;
                if ( d[v] > du + uv ){
                    d[v] = du + uv;
                    ta[v]=u;
                    qu.push( ii(d[v],v) );
                }
         } else continue;
    }
}

int main()
{
    nhap();
    ///===khoitao;
    memset(ca,true,sizeof(ca));
    for (int i=1; i<=p; i++) ca[b[i]]=false;
    dijkstra(1,n);
    printf("%d ",d[n]);
    memset(ca,true,sizeof(ca));
    for  (int i=1; i<=q; i++) ca[c[i]]=false;
    dijkstra(n,1);
    printf("%d",d[1]);

}
