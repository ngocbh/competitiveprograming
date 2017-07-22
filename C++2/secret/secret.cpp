//#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <queue>
#define maxN 100000+100
#define maxM 3*100000+100
#define oo 1000000000+1000000+11111
using namespace std;
int n,m,s,t,ca[maxN],f[maxN],d[maxN];
vector <int> a[maxN];
void khoitao()
{
    memset(ca,true,sizeof(ca));
    memset(d,0,sizeof(d));
}
void bfs()
{   queue <int> qe;
  //  fr[s]=false;
    memset(ca,true,sizeof(ca));
    d[s]=1;
    f[s]=1;
    qe.push(s);
    while (!qe.empty()){
        int u,v; u=qe.front();
         qe.pop();
        for (int i=0; v=a[u][i]; i++)
            if ( ca[v]) {
            d[v]=d[u]+1;
            ca[v]=false;
            f[v]=f[u];
            qe.push(v);
        }
        else
            if (d[v]==d[u]+1) f[v]=(f[u]+f[v]) % 1000000007;
    }
}
void dfs(int u)
{  int v;
    ca[u]=false;
    for (int i=0; v=a[u][i]; i++)if (ca[v] ){
        f[v]=f[u]+f[v];
        dfs(v);
    }
}
int main()
{   freopen("secret.inp","r",stdin);
    freopen("secret.out","w",stdout);
    scanf("%d%d" ,&n,&m);
    scanf("%d%d" ,&s,&t);
    for (int i=1; i<=m; i++){
        int u,v;
        scanf("%d %d",&u,&v );
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for ( int i=1; i<=n; i++ ) a[i].push_back(0);
    //khoitao();
    bfs();
    memset(ca,true,sizeof(ca));

    printf("%d\n", f[t]);


}
