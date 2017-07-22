#include <iostream>
#include <stdio.h>
#include <cmath>
#define maxn 500
#define maxa 1000000000+7
using namespace std;
int n,m,d[maxn][maxn],a[maxn][maxn],s,t;
void floyd()
{
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
              a[i][j]=min( a[i][j], a[i][k] + a[k][j] );
    cout<<a[s][t]<<endl;

}
int main()
{   freopen("floyd.inp","r",stdin);
    freopen("floyd.out","w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) a[i][j]=maxa;
    for (int i=1; i<=n; i++) a[i][i]=0;
    for (int i=1; i<=m; i++) {
        int u,v,k;
        cin>>u>>v>>k;
        a[u][v]=k;
        a[v][u]=k;
    }
    floyd();
}
