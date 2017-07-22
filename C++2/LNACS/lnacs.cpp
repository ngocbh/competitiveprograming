#include <iostream>
#include <stdio.h>
#include <memory.h>
#define maxn 1000+10
using namespace std;
int n,m,a[maxn],b[maxn],f[maxn][maxn];
int main()
{  // freopen("lnacs.inp","r",stdin);
   // freopen("lnacs.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=m; i++) cin>>a[i];
    for (int i=1; i<=n; i++) cin>>b[i];
    memset(f,0,sizeof(f));
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (a[i]==b[j]){
                if (i==1 || j==1) {
                    f[i][j]=1;
                }else
                f[i][j]=max(f[i-1][j-1],f[i-2][j-2]+1);
            }
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
    cout<<f[m][n];
}
