#include <fstream>
#include <queue>
#include <vector>
#include <memory.h>
#include <iostream>
#define maxn 101
#define maxm 10100
#define oo 1000111000
using namespace std;
ifstream fi("rblock.inp");
ofstream fo("rblock.out");

typedef pair<int,int> ii;
int n,m,c[maxn][maxn],d[maxn],rr,res=0;
vector <ii> a[maxn];
ii tt[maxm];

void nhap()
{
    fi>>n>>m;
   for (int i=1; i<=m; i++) {
        int u,v,k;
        fi>>u>>v>>k;
        a[u].push_back(ii(k,v));
        a[v].push_back(ii(k,u));
        tt[i]=make_pair(u,v);
}
for (int j=1; j<=n; j++) a[j].push_back(ii(0,0));
}
void dijkstra()
{
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    int i, u, v, du, uv;
    for (i=1; i<=n; i++) d[i] = oo;
    d[1] = 0;
    pq.push(ii(0, 1));

    while (pq.size()){
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;

        for (i=0; v=a[u][i].second; i++)
        {
            uv=a[u][i].first;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }

}
int main()
{  nhap();

dijkstra();
rr=d[n];
for (int i=1; i<=m; i++){
    int nho1=0,nho2=0,u,v;
    u=tt[i].first; v=tt[i].second;
     for (int j=0; j<=a[u].size(); j++)
        if ( a[u][j].second==v ) {nho1=j; a[u][j].first*=2; break;}
     for (int j=0; j<=a[v].size(); j++)
        if ( a[v][j].second==u ) {nho2=j; a[v][j].first*=2; break;}
        for (int j=1; j<=a[v].size(); j++)
         //   cout<<a[u][nho1].first<<" ";
      //  cout<<endl;
    //cout<<u<<" "<<v<<endl;
    //cout<<a[u][nho1].first<<" "<<" "<<a[u][nho1].second<<" "<<nho1<<" "<<a[v][nho2].first<<" "<<" "<<a[u][nho2].second<<" "<<nho2<<endl;
    dijkstra();
    int rr1;
    rr1=d[n];
    //fo<<nho1<<" "<<nho2<<endl;
    if (rr1-rr>res) res=rr1-rr;
    a[u][nho1].first/=2;
    a[v][nho2].first/=2;
       // cout<<a[u][nho1].first<<" "<<" "<<a[u][nho1].second<<" "<<nho1<<" "<<a[v][nho2].first<<" "<<" "<<a[u][nho2].second<<" "<<nho2<<endl;

}
fo<<res;

}
