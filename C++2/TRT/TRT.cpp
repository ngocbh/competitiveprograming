#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
const long N = 2000 +5 ;
using namespace std;
int n , a[N] , f[N][N] ;

void inp()
{
    freopen("TRT.inp","r",stdin);
    //freopen("TRT.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1 ; i <= n ; i++ ) scanf("%d ", &a[i]);
}

void dynamic()
{   int j,cs;
    for (int l = 0 ; l < n; l++)
        for (int i = 1; i <= n; i++) {
            j = i+l ;
            cs = n- ( j - i ) ;
            f[i][j] = max( f[i][j-1] + a[j] * cs , f[i+1][j] + a[i] * cs );
        }
    cout<<f[1][n];
}
int main()
{   inp();
    dynamic();
}
