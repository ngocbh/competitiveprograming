#include <iostream>
#include <stdio.h>
#include <memory.h>
#define maxn 10000+100
using namespace std;
int m,n,a[maxn][maxn],kq[maxn],f[maxn][maxn],ss=0;
bool ca[maxn][maxn];
void dfs(int x,int y)
{
    for (int i=-1; i<=1; i++)
        for (int j=-1; j<=1; j++)
            if (i!=0 || j!=0)
                if (a[x+i][y+j]==0){
                    ++kq[ss];
                    f[x+i][y+j]=ss;
                    ca[x+i][y+j]=false;
                    dfs(x+i,y+j);
                } else {f[x+i][y+j]=-1; ca[x+i][y+j]=false;}
}
void tplt()
{
    for (int i=1; i<=m; i++)
        for (int j=1 ;j<=n; j++)
            if ( ca[i][j] ){
               ++ss;
                dfs(i,j);
        }

}
int main()
{
  freopen("hcn.inp","r",stdin);
  freopen("hcn.out","w",stdout);
  scanf("%d %d" , &m , &n);
  memset(ca,true,sizeof(ca));
  for (int i=1; i<=m; i++)
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) scanf("%d" ,&a[i][j]);
  for (int i=1; i<=m; i++) f[i][0]=1;
  for (int i=1; i<=n; i++) f[0][i]=1;
  ///==================
  tplt();
}
