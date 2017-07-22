#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define maxn 1000+100
#define maxa 1000000000+7
#define st first
#define nd second
using namespace std;
int n,m,a[maxn][maxn],res=0;
pair <int,int> f[maxn][maxn];
int main()
{
    freopen("BOB.inp","r",stdin);
    freopen("BOB.out","w",stdout);
    scanf("%d %d" , &n,&m);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) scanf("%d",&a[i]);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            if ( a[i][j]==a[i-1][j] ) f[i][j].st=f[i][j].st+1;
                else f[i][j].st=1;
            if ( a[i][j] )
        }
}
