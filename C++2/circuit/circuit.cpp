#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory.h>
#define maxn 100000+100
using namespace std;
int n,m,ca[maxn],cc[maxn],kq[maxn],ta[maxn],d[maxn],in[maxn];
bool kt;
typedef pair<int,int> ii;
vector <ii> a[maxn];
void ikq(int u,int v)
{

}
void dfs(int u)
{   if (kt) return ;
    ca[u]=false;
    in[u]=true;
    for (int i=0; i<=a[u].size()-1; i++){
        if (!ca[a[u][i].first]) {  printf("YES\n");
    int dem=1;
    kq[dem]=a[u][i].second;
     while (u!= a[u][i].first){
        kq[++dem]=d[u];
        u=ta[u];
    }
    for (int i=1; i<=dem; i++) printf("%d ",kq[i]); kt=true; return;  }
        if (!in[a[u][i].first]) return;
        ta[a[u][i].first]=u;
        d[a[u][i].first]=a[u][i].second;
        dfs(a[u][i].first);
    }
    ca[u]=true;

}
void solve1()
{   kt=false;
    memset(ca,true,sizeof(ca));
    memset(in,false,sizeof(in));
    for (int i=1; i<=n; i++)
    if (ca[i] && !kt) {
        dfs(i);
    }
    if (!kt) printf("NO");
}
int main()
{   freopen("circuit.inp","r",stdin);
    freopen("circuit.out","w",stdout);
   scanf("%d %d" , &n, &m);
   for (int i=1; i<=m; i++) {
        int u,v;
        if (u==v) continue;
        scanf("%d %d" , &u , &v);
        a[u].push_back(ii(v,i));
   }
   solve1();
}
