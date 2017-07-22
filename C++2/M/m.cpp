#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#define maxn 100000+100
using namespace std;
int n,a[maxn],f1[maxn],f2[maxn],res,d1,d2,d3,d4,d5;
int main()
{   freopen("m.inp","r",stdin);
    freopen("m.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    ///=====================
    f1[1]=1;
    f2[1]=1;
    for (int i=2; i<=n; i++){
        if ( a[i]>a[i-1] ) f1[i]=f1[i-1]+1;
        else f1[i]=f1[i-1];
        if ( a[i]<a[i-1] ) f2[i]=f2[i-1]+1;
        else f2[i]=f2[i-1];
    }
    ///=====================

    for (int i=2; i<=n-4; i++)
        for (int j=i+2; j<=n-2; j++)
            for ( int ij=i+1; ij<=j-1; ij++){
                d1=f1[i];
                d2=f2[ij]-f2[i];
                d3=f1[j]-f1[ij];
                d4=f2[n]-f2[j];
                if ( d1>0 && d2>0 && d3>0 && d4 >0 ) res=max( res, d1+d2+d3+d4 );
            }
    cout<<res;
}
