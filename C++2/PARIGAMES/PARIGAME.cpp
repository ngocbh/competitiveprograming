#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#define maxn 500+10
using namespace std;
int n,m,a[maxn][maxn],f[maxn][maxn],c[maxn][maxn],h[maxn][maxn];
void init()
{   memset(h,0,sizeof(h));
    memset(c,0,sizeof(c));
    memset(f,false,sizeof(f));
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++){
            c[i][j]=c[i-1][j]+a[i][j];
            h[i][j]=h[i][j-1]+a[i][j];
        }
}
void dynamic()
{
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) {
            int jj=j,ii=i;
            while ( c[i][jj] % 2 == 0 && jj>0 ) --jj;
            while ( h[ii][j] % 2 == 0 && ii>0 ) --ii;
           // cout<<ii<<" "<<jj<<endl;
            if ( !f[i][jj] && c[i][j] % 2 == 0 ) f[i][j]=true;
            if ( !f[ii][j] && h[i][j] % 2 == 0 ) f[i][j]=true;
        }
    //cout<<c[2][2]<<" ";
    if ( f[m][n] ) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
}
void inp()
{
    cin>>m>>n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) cin>>a[i][j];
}
void xuly()
{
    inp();
    init();
    dynamic();
}
int main()
{   freopen("PARIGAME.inp","r",stdin);
    freopen("PARIGAME.out","w",stdout);
    int t; cin>>t;
    while ( t-- ) xuly();
}
