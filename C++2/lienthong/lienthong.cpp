#include <iostream>
#include <stdio.h>
#include <memory.h>
#define maxn 10000+10
using namespace std;
int n,a[maxn][maxn],kq[maxn][maxn],ca[maxn],ss=0,ll;
void dfs(int x)
{
    for (int j=1; j<=n; j++)
        if (ca[j] && a[x][j]==1){
             ca[j]=false;
             kq[ss][++ll]=j;
             dfs(j);

        }
}
void tplt()
{   memset(ca,true,sizeof(ca));
    for (int i=1; i<=n; i++)
        if (ca[i]){
              ++ss;
              ca[i]=false;
              ll=0;
              kq[ss][++ll]=i;
              dfs(i);
              kq[ss][0]=ll;
        }
}
int main()
{   freopen("lienthong.inp","r",stdin);
    freopen("lienthong.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) scanf("%d",&a[i][j]);
    tplt();
    for (int i=1; i<=ss; i++){
        for (int j=1; j<=kq[i][0]; j++)
            printf("%d ",kq[i][j]);
            printf("\n");
    }
    ///==============
}
