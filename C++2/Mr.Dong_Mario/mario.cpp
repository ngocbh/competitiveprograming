#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#define maxn 5000+10
using namespace std;
int64_t n,m,x,y,t,a[maxn][maxn],res=0,ress=0,tt=0;
int64_t f[2][maxn][maxn];
int tx[5]={0,0,0,1,-1},
    ty[5]={0,1,-1,0,0};
int main()
{   freopen("mario.inp","r",stdin);
    freopen("mario.out","w",stdout);
    cin>>m>>n>>x>>y>>t;
    for (int i=1; i<=m; i++)
         for (int j=1; j<=n; j++) cin>>a[i][j];
///================khoitao;
   for (int k=0; k<=1; k++)
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++) f[k][i][j]=-1;
    f[0][x][y]=0;
    int tf;
    tf=min(m*n,t);
///================taomangf kiemtraluon :D;
    for (int k=0; k<=tf; k++)
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++) if ( f[k%2][i][j]!=-1 )  {
                for (int h=1; h<=4; h++)
                 {    int u=0,v=0;

                    u=i+tx[h];
                    v=j+ty[h];

                    if ( 1<=u && u<=m && 1<=v && v<=n  ) {
                    if ( f[k%2][i][j] + a[u][v] > f[(k+1)%2][u][v] ) f[(k+1)%2][u][v]=f[k%2][i][j] + a[u][v];
                    //=====
                    int64_t ress=0,uv;
                    uv=a[u][v]+a[i][j];
                    ress+=f[k%2][i][j]+uv * ((t-k)/2)  ;
                    if ( t-k % 2 == 1 ) ress+=a[u][v];
                    res=max(res,ress);
                    }

                }
            }

      cout<<res;
}

