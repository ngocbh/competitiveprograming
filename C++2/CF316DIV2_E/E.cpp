#include <bits/stdc++.h>

const long N = 500 + 5;
using namespace std;
int n, m,len, f[N][N], ans = 0;
char a[N][N];
int main()
{   freopen("E.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j] ;
    len = m+n-1;
    for (int ci = 1; ci <= n; ci++) {
        int cj;
        cj = (len+1)/2 + 2 - ci;
        if ( cj <= 0 ) continue;
        memset(f,0,sizeof f);
        for (int i = ci; i <= n; i++)
            for (int j = cj; j <= m; j++) {

            }
    }

    cout <<ans;
}
