#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <memory.h>
#define maxn 10000+100
#define oo 100000000+17;
using namespace std;
typedef pair <int,int> ii;
int n,m,s,t,d[maxn],ta[maxn];
bool ca[maxn];
vector <ii> a[maxn];
void khoitao()
{
    for (int i=1; i<=n ;i++) a[i].push_back(ii(0,0));
    memset(ca,true,sizeof(ca));
    for (int i=1; i<=n; i++) d[i]=oo;
    d[s]=0;

}
void dijkstra()
{
    while ( true ){
            int u=0,v,min1=oo;
            for (int i=1; i<=n; i++)
                if ((ca[i]) && (d[i]<min1)){
                    u=i;
                    min1=d[i];
                }
            if ( u==0 || u==t ) break;

            ca[u]=false;
            for (int i=0; v=a[u][i].second; i++){
                int uv=a[u][i].first;
                if ( ca[v] && (d[v] > d[u]+ uv) ){
                    d[v]=d[u]+uv;
                    ta[v]=u;
                }
            }

    }
}
void truyvet()
{
    if ( d[t]==0  ) cout<<"Khong co duong di ";
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
{
    freopen("dijkstra.inp","r",stdin);
    freopen("dijkstra.out","w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1; i<=m; i++){
        int u,v,k;
        cin>>u>>v>>k;
        a[u].push_back( ii( k,v ) );
        a[v].push_back( ii( k,u ) );
    }
    khoitao();
    dijkstra();
    truyvet();
}
