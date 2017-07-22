#include <bits/stdc++.h>

const long N = 10000 + 100;
using namespace std;
int t, n, a[N], f[N];
bool solve(int c1,int c2,int c3)
{
    if ( c1 == 1 ) f[1] = -a[1];
    else f[1] = a[1];
    if ( c2 == 1 ) f[2] = -a[2];
    else f[2] = a[2];
    if ( c3 == 1 ) f[3] = -a[3];
    else f[3] = a[3];
    for (int i = 4; i <= n+3; i++) {
        f[i] = 1 / ( f[i-1] * f[i-2] * f[i-3] );
        if ( i % 2 == 0 ) {
            f[i] = -f[i];
        }

    }
    for (int i = 1; i <= 3; i++) {
        if ( f[i] != f[n+i] ) return false;
    }
    for (int i = 1; i <= n; i++) printf("%d ", f[i]);
    printf("\n");
    return true;
}
int main()
{   //freopen("PRCNSR4.inp","r",stdin);
    scanf("%d", &t);
    while ( t -- ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) printf("%d " , -a[i]);
        printf("\n");

    }
}
