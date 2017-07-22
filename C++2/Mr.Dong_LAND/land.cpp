#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define maxn 100
using namespace std;
int n,m,k,a[maxn],b[maxn],c[maxn][maxn],sum=0,kk,res=0,kl,aa[maxn],bb[maxn];
bool ok=false;
bool realvodoi(int aa,int bb,int xx,int yy)
{
    for (int i=xx; i<=xx+aa-1; i++)
        for (int j=yy; j<=yy+bb-1; j++)
            if ( c[i][j]==1 ) return false;
    return true;
}
void dat(int aa,int bb,int xx,int yy,int oo)
{
    for (int i=xx; i<=xx+aa-1; i++)
        for (int j=yy; j<=yy+bb-1; j++)
            c[i][j]=oo;
}
void duyet(int i)
{   if ( ok ) return;
    if ( i > k ) { res=kl; ok=true; return; }
    for (int x=1; x<=m; x++)
        for (int y=1; y<=n; y++) if ( c[x][y]==0  ) {
            if ( c[x+a[i]-1][y+b[i]-1]==0 )
            if ( realvodoi( a[i],b[i],x,y ) )
            {
                dat(a[i],b[i],x,y,1);
                duyet(i+1);
                dat(a[i],b[i],x,y,0);
            }
            if ( c[x+b[i]-1][y+a[i]-1]==0 )
            if ( realvodoi( b[i],a[i],x,y ) )
            {
                dat(b[i],a[i],x,y,1);
                duyet(i+1);
                dat(b[i],a[i],x,y,0);
            }
        }
}
bool cmp(int i,int j)
{
    return aa[i]*bb[i]>aa[j]*bb[j];
}
int main()
{   freopen("land.inp","r",stdin);
    freopen("land.out","w",stdout);
    cin>>m>>n>>k;
    for (int i=1; i<=k; i++) {cin>>a[i]>>b[i]; sum=sum+a[i]*b[i];  aa[i]=a[i]; bb[i]=i;}
    kk=(int) sqrt( m*n-sum ); ++k;
    for (int i=m+1; i<=m+20;i++)
        for (int j=1; j<=n+20; j++) c[i][j]=1;
    for (int i=1; i<=m+20;i++)
        for (int j=n+1; j<=n+20; j++) c[i][j]=1;
///=============================================


    for (int o=kk; o>=1; o--){
        for (int i=1; i<=k; i++) a[i]=aa[i];
        a[k]=o; aa[k]=o;
        b[k]=o; bb[k]=o;
        kl=o;
        for (int i=m+1; i<=m+20;i++)
        for (int j=1; j<=n+20; j++) c[i][j]=1;
        ///=================================
        for (int i=1; i<=m+20;i++)
        for (int j=n+1; j<=n+20; j++) c[i][j]=1;
        duyet(1);
        if ( ok  ) { cout<<res*res; return 0; }
    }
    cout<<0;
}
