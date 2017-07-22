/*#include <iostream>
#include <stdio.h>
#include <cmath>
#define maxn 500+10
#define maxm 10000
#define oo 1e9+7
using namespace std;
int n,m,ff,f[maxn],t[maxm],a[maxn][maxn],res,kq;
void floyd()
{
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                a[i][j]=min( a[i][j] , a[i][k]+a[k][j] );
}
int main()
{   freopen("bestspot.inp","r",stdin);
    freopen("bestspot.out","w",stdout);
    cin>>n>>ff>>m;
    ///khoitao;
    for (int i=1; i<=n;i++)
        for (int j=1; j<=n; j++) a[i][j]=oo;
    for (int i=1; i<=n; i++) a[i][i]=0;
    ///=================
    for (int i=1; i<=ff; i++) cin>> f[i];
    for (int i=1; i<=m; i++) {
        int u,v,k;
        cin>>u>>v>>k;
        a[u][v]=k;
        a[v][u]=k;
    }
    floyd();
    res=oo;
    for (int i=1; i<=n; i++){ int ress=0;
        for (int j=1; j<=ff; j++) ress+=a[i][f[j]];
        //if ( i==10 ) cout<<ress<<endl;
        if ( res > ress ) { res=ress; kq=i; }
    }
    cout<<kq;
}*/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <queue>
#define maxn 500+10
#define maxm 10000
#define oo 1e9+7
using namespace std;
typedef pair <int,int> ii;
int n,m,d[maxn],ca[maxn],f[maxn],res,kq,ff;
vector <ii> a[maxn];
void dijkstra(int x)
{   priority_queue <ii , vector<ii> , greater<ii> > qu;
    for (int i=1; i<=n; i++) d[i]=oo;
    d[x]=0;
    qu.push( ii( 0,x ) );
    while ( qu.size() ){
        int u,v,uv,du;
        u=qu.top().second;
        du=qu.top().first;
        qu.pop();
        if ( du != d[u] ) continue;
        for (int i=0; v=a[u][i].second; i++) {
            uv=a[u][i].first;
            if ( d[v] > d[u]+uv  ) {
                d[v]=d[u]+uv;
                qu.push( ii(d[v],v) );
            }
        }
    }
}
int main()
{   //freopen("bestspot.inp","r",stdin);
    //freopen("bestspot.out","w",stdout);
    cin>>n>>ff>>m;
    for (int i=1; i<=ff; i++) cin>>f[i];
    for (int i=1; i<=m; i++) {
        int u,v,k;
        cin>>u>>v>>k;
        a[u].push_back( ii( k,v ) );
        a[v].push_back( ii( k,u ) );
    }
    for (int i=1; i<=n; i++) a[i].push_back( ii(0,0) );
    res=oo;
    for (int i=1; i<=n; i++) {
        dijkstra(i);
        int ress=0;
        for ( int o=1; o<=ff; o++ ) ress+=d[f[o]];
        if ( res > ress ) { res=ress; kq=i; }
    }
    cout<<kq;
}

















