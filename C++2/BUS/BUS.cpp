#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>

using namespace std;

const long  maxmax = 250000,z=0;
long        n,m,k,t,f[maxmax],a[maxmax],p,x,res;

int main()
{   freopen("BUS.inp","r",stdin);
    freopen("BUS.out","w",stdout);
    cin>>n>>m;
    f[1] = 0;
    p = 0;
    for (long i=1;i<=n;i++) {
        cin>>t>>k;
        f[i+1] = f[i] + t;
        for (long j=p+1;j<=p+k;j++) {
            scanf("%li",&x);
            a[j] = max(z,x-f[i]);
        }
        p += k;
    }
    sort(a+1,a+p+1);
    res = f[n+1]+a[m];
    cout<<res;
    return 0;
}
