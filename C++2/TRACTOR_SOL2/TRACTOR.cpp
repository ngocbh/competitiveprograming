/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 500 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, kt, ans;
int a[N][N], ca[N][N];
int h[5] = {0,0,0,1,-1};
int c[5] = {0,1,-1,0,0};

int dfs(int u,int v,int d)
{
    ca[u][v] = false;
    int C = 1;
    for (int i = 1; i <= 4; i++) {
        int ui = u+h[i];
        int vi = v+c[i];
        if ( ui < 1 || ui > n || vi < 1 || vi > n ) continue;
        if ( abs(a[u][v] - a[ui][vi]) <= d && ca[ui][vi] ) {
            C += dfs(ui,vi,d);
        }
    }
    return C;
}

bool check(int d)
{
    int res = 0;
    memset(ca,true,sizeof ca);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)    {
            if ( !ca[i][j] ) continue;
            res = max(res,dfs(i,j,d));
        }
    if ( res >= kt ) return true;
    else return false;
}

int main()
{
    freopen("TRACTOR.inp","r",stdin);
    freopen("TRACTOR.out","w",stdout);

    cin >> n;
    kt = (n*n+1)/2;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    int l = 0, r = 1000000 + 1, ans = -1;
    while ( l <= r ) {
        int m = (l+r)/2;
        if ( !check(m) ) {
            l = m+1;
            ans = m;
        }
        else r = m-1;
    }

    cout << ans+1;
}
