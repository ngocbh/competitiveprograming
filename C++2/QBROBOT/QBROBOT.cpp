#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <memory.h>
#define maxn 1000
#define maxm 30000+10
#define maxa 1000000000+7
using namespace std;
int station[maxn],ca[maxn],t[maxn][maxn],c[maxn][maxn],ta[maxn],d[maxn],s[maxn],minC;
int n,m,res=0,ress,restime=0,resstime=0;
int cw=0;
vector <int> a[maxn],trace[maxn];
void inp()
{
    //freopen("QBROBOT.inp","r",stdin);
    //freopen("QBROBOT.out","w",stdout);
        cin>>n;
        for (int i=1; i<=n; i++) scanf("%d",&station[i]);
        cin>>m;
        for (int i=1; i<=m; i++) {
            int u,v,tt,cc;
            cin>>u>>v>>tt>>cc;
            a[u].push_back(v);
            a[v].push_back(u);
            t[u][v]=tt; t[v][u]=tt;
            c[u][v]=cc; c[v][u]=tt;
        }
         for (int i=1; i<=n ;i++) a[i].push_back(0);

}
void init(int w)
{

    for (int i=1; i<=n; i++) d[i]=maxa;
    memset(ca,true,sizeof(ca));
    memset(s,0,sizeof(s));
    d[1]=0;
    s[1]=w;
}
void dijkstra_check()
{
    init(10000);
    while ( true ){
            int u=0,v,min1=maxa;
            for (int i=1; i<=n; i++)
                if ((ca[i]) && (d[i]<min1)){
                    u=i;
                    min1=d[i];
                }
            if ( u==0 ) break;

            ca[u]=false;
            for (int i=0; v=a[u][i]; i++){
                int uv=t[u][v];
                if ( ca[v] && (d[v] > d[u]+ uv)  ){
                    d[v]=d[u]+uv;
                }
            }

    }
    minC=d[n];
}
int dijkstra(int w)
{

    while ( true ){
            int u=0,v,min1=maxa;
            for (int i=1; i<=n; i++)
                if ((ca[i]) && (d[i]<min1)){
                    u=i;
                    min1=d[i];
                }
            if ( u==0 ) break;

            ca[u]=false;
            for (int i=0; v=a[u][i]; i++){
                int uv=t[u][v];
                if ( ca[v] && (d[v] > d[u]+ uv) && s[u] >= c[u][v] ){
                    d[v]=d[u]+uv;
                    ta[v]=u;
                    s[v]=s[u]-c[u][v];
                    if ( station[v] ) s[v]=w;
                }
            }

    }
    return d[n];
}

bool check_w(int w)
{
   init(w);
   dijkstra(w);
   if ( d[n] == minC ) return true;
   return false;
}
void solve()
{
    int l=1,r=10000;
    while ( l <= r ){
        int mid;
        mid=(l+r)/2;
        if ( !check_w(mid) ) res=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<res+1;
}
int main()
{   inp();
    dijkstra_check();
    solve();
}
