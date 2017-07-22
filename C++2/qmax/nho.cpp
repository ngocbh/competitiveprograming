#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
using namespace std;
const long  maxn = 50000+100;
long        n,m,k,u,v,q,L,R,a[maxn],t[4*maxn],res;

void update(long k,long l,long r) {
    if (l == r) t[k] = a[l];
    else {
        long m = (l+r)/2;
        update(k*2,l,m);
        update(k*2+1,m+1,r);
        t[k] = max(t[k*2],t[k*2+1]);
    }
}

void findres(long k,long l,long r) {
    if (not(r < L or R < l)) {
        if (L <= l and r <= R)
            res = max(res,t[k]);
        else {
            long m = (l+r)/2;
            findres(k*2,l,m);
            findres(k*2+1,m+1,r);
        }
    }
}

int main()
{   freopen("qmax.inp","r",stdin);
   freopen("qmax.out","w",stdout);
    scanf("%li%li",&n,&m);
    for (long i=1;i<=m;i++) {
        scanf("%li%li%li",&u,&v,&k);
        a[u] += k;
        a[v+1] -= k;
    }
    for (long i=1;i<=n;i++) a[i] += a[i-1];
    update(1,1,n);
    scanf("%li",&q);
    for (long Q=1;Q<=q;Q++) {
        scanf("%li%li",&L,&R);
        res = 0;
        findres(1,1,n);
        printf("%li\n",res);
    }
    return 0;
}
