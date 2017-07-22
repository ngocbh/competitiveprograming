#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>

const long N = 100 + 5;
using namespace std;
int n,res,scs,k,a[N],sl=0;
int64_t t,tt;
int main()
{   freopen("TABLE.inp","r",stdin);
    //freopen("TABLE.out","w",stdout);
    scanf("%d %d ", &n, &t);
    res = 1; scs = 1; t -= n ;
    while ( t > res * 9 * scs ) {
        t -= res * 9 * scs ;
        ++scs;
        res *= 10;
    }
    int i,ress=res;
    res = res + t / scs; k = t % scs  ; i = scs;
    while ( i > k ) {
        a[i-k] = ress % 10;
        ress /= 10;
        ++sl;
        --i;
    }
    for (int i=1; i<=sl; i++) cout<<a[i];
    while ( sl + scs < n ) {
        ++res;
        cout<<res;
        sl += scs;
    }
    i = scs; ++res; sl = n - scs;
    //while (  )
}
