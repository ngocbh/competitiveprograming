#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <memory.h>

const long N = 10000+5;
using namespace std;
int n,k,a[N];
int64_t res=0;
int main()
{   freopen("EXPRESS.inp","r",stdin);
    freopen("EXPRESS.out","w",stdout);
    scanf("%d %d ", &n, &k);
    for (int i=1; i<=n; i++)
        scanf("%d ", &a[i]);
    sort(a+2,a+n+1);
    res = a[1];
    for (int i=2; i<=n; i++){
        if ( i <= n - 1 - k ) res = res - a[i];
        else res += a[i];

    }
    printf("%d ", res);
}
