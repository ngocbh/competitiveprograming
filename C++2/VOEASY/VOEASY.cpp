#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#define maxn 10
using namespace std;
int n,m,k,a[2][maxn],f[3][1000];
void xuly(int x,int ic,int im)
{
    for (int i=n*(x-1)+1; i<=n*x; i++ ){
        int ss=n*(x-1);
        if ( f[1][i] == 1 )
        a[im][i-ss]=a[ic][ f[0][i] ] & a[ic][ f[2][i] ];
        if ( f[1][i] == 2 )
        a[im][i-ss]=a[ic][ f[0][i] ] | a[ic][ f[2][i] ];
        if ( f[1][i] == 3 )
        a[im][i-ss]=a[ic][ f[0][i] ] ^ a[ic][ f[2][i] ];
    }
}
int main()
{   //freopen("VOEASY.inp","r",stdin);
    //freopen("VOEASY.out","w",stdout);
    cin>>n>>m>>k;
    int ll=0;
    for (int i=1; i<=n; i++) cin>>a[0][i];
    for (int i=1; i<=m ; i++)
        for (int j=1; j<=n; j++ ) {
        ++ll;
        int u,v; string c;
        cin>>f[0][ll]>>c>>f[2][ll];
        if ( c=="and" ) f[1][ll]=1;
        if ( c=="or" ) f[1][ll]=2;
        if ( c=="xor" ) f[1][ll]=3;
    } int ic=0, im=1;
    for (int i=1; i<=k+1; i++) {
        int j;
        j=i % m;
        if ( j==0 ) j=m;
        xuly(j,ic,im);
        ic=1-ic;
        im=1-im;
        // for (int i=1; i<=n; i++) cout<<a[im][i]<<" "; cout<<endl;
    }
    for (int i=1; i<=n; i++) cout<<a[im][i]<<" "; cout<<endl;
}
