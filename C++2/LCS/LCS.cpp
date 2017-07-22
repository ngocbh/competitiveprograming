#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <vector>
#define maxn 1000000+100
#define maxm 1000+100
using namespace std;
int n,m,a[maxm],b[maxn],kq[maxn];
vector <int> aa[maxn];
int main()
{   freopen("LCS.inp","r",stdin);
    freopen("LCS.out","w",stdout);
    scanf("%d %d",&m , &n);
    for (int i=1; i<=m; i++) scanf("%d",&a[i]);
    for (int i=1; i<=n; i++) scanf("%d",&b[i]);
    int f[m+1][n+1];
    memset(f,0,sizeof(f));
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
          if ( a[i]==b[j] ) f[i][j]=f[i-1][j-1]+1;
          else f[i][j]=max( f[i-1][j] , f[i][j-1] );
    cout<<f[m][n]<<endl;
    int nhom=m,nhon=n,res=f[m][n];
    int i=m,j=n;
    while ( i>1 )
    while ( j>1 ) {
        if ( f[i][j]==f[i-1][j-1]+1 ) { kq[res]=a[i]; --res; --i; --j; }
        else
            if ( f[i][j]==f[i-1][j] ) --i;
            else --j;
    }
    for (int i=1; i<=f[m][n]; i++) cout<<kq[i]<<" ";
}
