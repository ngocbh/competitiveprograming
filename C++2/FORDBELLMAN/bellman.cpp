#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <cmath>
#include <memory.h>
#define maxn 10000+10
#define maxa 1000000000+7
using namespace std;
typedef pair <int,int> ii;
int m,n,s,t,ca[maxn],d[maxn],aa[maxn][maxn];
vector <ii> a[maxn];
void bellmanqueue()
{   queue <int> qu;
    for (int i=1; i<=n; i++) d[i]=maxa;
    for (int i=1; i<=n-1; i++) {
    memset(ca,true,sizeof(ca));
    qu.push( s );
    d[s]=0;
    ca[s]=false;
    while ( !qu.empty() ){
       int u,v;
       u = qu.front(); qu.pop(); ca[u]=false;
       for (int i=0; v=a[u][i].second; i++ ) {
            if ( d[v] > d[u]+a[u][i].first )
                 d[v]=d[u]+a[u][i].first;
            if ( ca[v] ){
                qu.push( v );
                ca[v]=false;
            }
       }
    }
    }
    cout<<d[t]<<endl;
}
void bellman()
{   bool ok = false;
    for (int i=1; i<=n; i++) d[i]=maxa;
    d[s]=0;
    for (int i=1; i<=n-1; i++) {
    for (int u=1; u<=n; u++)
        for (int v=1; v<=n; v++)
            d[v]=min( d[v],d[u]+aa[u][v] );
    }
    cout<<d[t]<<endl;
}
int main()
{   freopen("bellman.inp","r",stdin);
    freopen("bellman.out","w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) aa[i][j]=maxa;
    for (int i=1; i<=n; i++) aa[i][i]=0;
    for (int i=1; i<=m; i++) {
        int u,v,k;
        cin>>u>>v>>k;
        a[u].push_back( ii( k,v ) );
        a[v].push_back( ii( k,u ) );
        aa[u][v]=k;
        aa[v][u]=k;
    }
    for (int i=1; i<=n; i++) a[i].push_back( ii(0,0) );
    bellmanqueue(); /// O( n*m )
   // bellman(); /// O ( n^3 )
}
