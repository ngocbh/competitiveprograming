#include <fstream>
#include <vector>
#include <memory.h>
#include <iostream>
#define maxn 100+10
#define oo 1000000000
//#define fi cin
//#define fo cout
using namespace std;
ifstream fi("hiway.inp");
ofstream fo("hiway.out");

int n,m,ta[maxn],f[maxn],d[maxn],kq[maxn],kq1[maxn],res=0,s,t;
bool ca[maxn][maxn],kt;
typedef pair <int,int> ii;
vector <ii> a[maxn];
void nhap()
{
    fi>>n>>m>>s>>t;

    for (int i=1; i<=m; i++){
        int u,v,k;
        fi>>u>>v>>k;
        a[u].push_back( ii(k,v) );
        a[v].push_back( ii(k,u) );
    }
    for (int i=1; i<=n; i++) a[i].push_back( ii(0,0) );
}
void khoitao()
{       for (int i=1; i<=n; i++) a[i].push_back( ii(0,0) );
    for (int i=1; i<=n; i++) d[i]=oo;
    d[s]=0;
    memset(f,true,sizeof(f));
    memset(ta,0,sizeof(ta));
    f[0]=false;
}
void dijkstra()
{
    while (true){
        int u=0,min1=oo;
        for (int i=1; i<=n; i++)
            if ( f[i] && min1>d[i] ){
                    min1=d[i];
                    u=i;
            }
        if (u==0 || u==t) break;

        f[u]=false;

        for (int v=0; v<=a[u].size()-1; v++)
            if (f[a[u][v].second] && d[a[u][v].second]>d[u]+a[u][v].first && ca[u][a[u][v].second]){
                    d[a[u][v].second]=d[u]+a[u][v].first;
                    ta[a[u][v].second]=u;
            }
    }
}
void ikq1()
{   res+=d[t]; if (d[t]==oo) { kt=true; return;}
    int dem=0, ff,ff1;
    ff=t;
    while (ff!=s){
        ++dem;
        kq[dem]=ff;
        ff1=ff;
        ff=ta[ff];
        ca[ff][ff1]=false;
        ca[ff1][ff]=false;
    }
    ++dem;
    kq[dem]=s;
    kq[0]=dem;
}
void ikq2()
{   res+=d[t]; if (d[t]==oo) { kt=true; return; }
    int dem=0, ff=t;
    while (ff!=s){
        ++dem;
        kq1[dem]=ff;
        ff=ta[ff];
    } ++dem;
    kq1[dem]=s;
    kq1[0]=dem;
}
void ikq()
{
    fo<<res<<endl;
    fo<<kq[0]<<" ";
    for (int i=kq[0]; i>=1; i--) fo<<kq[i]<<" "; fo<<endl;
    fo<<kq1[0]<<" ";
    for (int i=kq1[0]; i>=1; i--) fo<<kq1[i]<<" ";fo<<endl;
}
int main()
{    memset(ca,true,sizeof(ca)); kt=false;
        nhap();
            khoitao();
                dijkstra();
                    ikq1();
                        khoitao();
                            dijkstra();
                                ikq2();
                                    if (kt) fo<<-1;
                                     else ikq();

}
