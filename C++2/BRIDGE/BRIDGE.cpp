#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#define maxn 200
using namespace std;
int x,a,y,b,m,d[maxn],res=10000000;
int main()
{   freopen("BRIDGE.inp","r",stdin);
    freopen("BRIDGE.out","w",stdout);
    cin>>x>>a>>y>>b>>m;
    if ( a == b ) {cout<<( ((x+y)/m) * ( a )  ); return 0 ; }
    if ( a < b ) {
        swap(x,y);
        swap(a,b);
    }
    for (int i=1; i<=x; i++) {
        int j; j = i % m ;
        if ( j==0 ) j=m;
        d[j]+=a;
    }
    //for (int i=1; i<=m ;i++) cout<<d[i]<<" "; cout<<endl;
    int nho;
    for (int i=1; i<=m; i++)
     if ( d[i] != d[i+1] ) { nho=i; break; }
    if ( nho==m ) {
        for (int i=1; i<=y; i++) {
        int j; j = i % m ;
        if ( j==0 ) j=m;
        d[j]+=b;
    }
    for (int i=1; i<=m; i++) res=min(d[i],res); cout<<res; return 0;
    }
    while ( d[nho+1] < d[nho] ) {
            if ( y==0 ) break;
            for (int i=nho+1; i<=m; i++)
            {
                d[i]+=b;
                --y;
                if ( y==0 ) break;
            }
    }
    //for (int i=1; i<=m ;i++) cout<<d[i]<<" "; cout<<endl;

    for (int i=1; i<=y; i++) {
        int j; j = i % m ;
        if ( j==0 ) j=m;
        d[j]+=b;
    }
    //for (int i=1; i<=m ;i++) cout<<d[i]<<" "; cout<<endl;
    for (int i=1; i<=m; i++) res=min(d[i],res); cout<<res; return 0;
}
