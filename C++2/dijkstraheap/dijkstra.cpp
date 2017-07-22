#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>
#define maxn 100000+100
#define oo 1000000007
using namespace std;
typedef pair <int,int> ii;
int n,m,s,t,d[maxn],ta[maxn];
vector <ii> a[maxn];

void dijkstra()
{
    priority_queue <ii,vector<ii>,greater<ii> > qe;
    for (int i=1; i<=n; i++) d[i]=oo;
    d[1]=0;
    qe.push( ii(0,1) );
    while ( !qe.empty() ){
        int u,du;
        u=qe.top().second;
        du=qe.top().first;
        qe.pop();
        if ( du!=d[u] ) continue;
        int v;
        for (int i=0; v=a[u][i].second; i++)
            if ( d[v]>d[u]+a[u][i].first ){
                d[v]=d[u]+a[u][i].first;
                ta[v]=u;
                qe.push( ii( d[v],v ) );
            }
    }
}
void truyvet()
{
   if ( d[t]==oo ) cout<<"Khong co duong di";
    else {
        cout<<d[t]<<endl;
        while ( t!=s ){
            cout<<t<<" ";
            t=ta[t];
        }
        cout<<s;
    }
}
int main()
{   freopen("dijkstra.inp","r",stdin);
    freopen("dijkstra.out","w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1; i<=m; i++){
        int u,v,k;
        cin>>u>>v>>k;
        a[u].push_back( ii(k,v) );
        a[v].push_back( ii(k,u) );
    }
    for (int i=1; i <=n ;i++) a[i].push_back( ii( 0,0 ) );
    dijkstra();
    truyvet();

}

