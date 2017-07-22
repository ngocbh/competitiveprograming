#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#define maxn 100000+100
using namespace std;
int n,m,d[maxn],gr[maxn],ss=0,se=0,kq[maxn];
bool ca[maxn];
vector <int> a[maxn];
void dfs(int u)
{   ca[u]=false;
    for (int i=0; i<=a[u].size()-1; i++ )
        if (ca[a[u][i]]){
            dfs(a[u][i]);
    }
}
void solve1()
{
    memset(ca,true,sizeof(ca));
    ca[0]=false;
    for (int i=1; i<=n; i++)
    if (ca[i]){
        ++ss;
        gr[ss]=i;
        dfs(i);
    }

}
void solve2()
{
    memset(ca,true,sizeof(ca));
    ca[0]=false;
    for (int i=ss; i>=1; i--)
        if (ca[gr[i]]){
                ++se;

                kq[se]=gr[i];
                dfs(gr[i]);
        }
}
int main()
{
    //freopen("message.inp","r",stdin);
    //freopen("message.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; i++){
        int u,v;
        scanf("%d %d", &u,&v);
        a[u].push_back(v);

    }
    for (int i=1; i<=n; i++) a[i].push_back(0);
    ///============
   // for (int i=1 ; i<=n; i++){
  //      for (int j=0; j<=a[i].size()-1; j++) cout<<a[i][j]<<" ";
   //     cout<<endl;
  //  }
    solve1();
    //for (int i=1; i<=ss; i++) cout<<gr[i]<<" ";
    solve2();
    printf("%d\n",se);
   // for (int i=1; i<=se; i++) printf("%d ",kq[i]);
}
