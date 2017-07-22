#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
const long N = 2000+5;
using namespace std;

int64_t n , a[N][N] , f[N][N] ;
void inp()
{
    //freopen("LSFIGHT.inp","r",stdin);
    //freopen("LSFIGHT.out","w",stdout);
    scanf("%lld", &n);
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1; j <= n; j++) scanf("%lld", &a[i][j]);
}

void init()
{
    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= n ; j++)
            for (int k = 1; k <= n; k++)
                if ( a[i][j] == 0 && a[i][k] == 1 && a[k][j] == 1 ) a[i][j] = 1;
}
void solve()
{   int64_t res=0,kq[N];
    for ( int i=1; i<=n; i++ )
    {   int sl = 0;
        for (int j = 1; j <= n; j++)
            if ( a[i][j] ) ++sl;
        if ( sl == n ) kq[++res] = i ;
    }
    cout<<res<<'\n';
    for (int i = 1; i <= res; i++) cout<<kq[i]<<'\n';
}
int main()
{
    inp();
    init();
    solve();

}
