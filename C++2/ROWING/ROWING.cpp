/*
    * Code By NgocJr7
    * alg of Mr Hoang
    * DPT O(n*n*log(10^9))
    * alg chat nhi phan duong kinh. kiem tra xem co duong di nho hon k hay ko.
*/

#include <bits/stdc++.h>
#define x first
#define y second
const long N = 4 * 1000 + 10;
const long oo = 1000000000 + 7;
using namespace std;
typedef pair <int,int> ii;
typedef long long LL;

int n, h;
int ca[N];
LL d[N][N];
ii P[N];

LL kc(ii A,ii B)
{
    return 1LL*(A.x - B.x)*(A.x - B.x) + 1LL*(A.y - B.y)*(A.y - B.y);
}

bool dfs(int u,LL m)
{
    bool c = false;
    ca[u] = false;
    if ( u == n+1 ) return true;
    for (int i = 1;  i <= n+1*(u!=0); i++) {
        if ( !ca[i] ) continue;
        if ( d[u][i] >= m ) continue;
        c = c | dfs(i,m);
    }
    return c;
}

bool check(LL m)
{
    memset(ca,true,sizeof ca);
    bool c = dfs(0,1LL*m*m);
    return c;
}

int main()
{   freopen("ROWING.inp","r",stdin);
    freopen("ROWING.out","w",stdout);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> P[i].x >> P[i].y;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            d[i][j] = d[j][i] = kc(P[i],P[j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        d[0][i] = d[i][0] = 1LL*P[i].y * P[i].y;
        d[n+1][i] = d[i][n+1] = 1LL*(h - P[i].y)*(h - P[i].y);
    }

    int l = 1, r = oo, m, ans = 0;
    while ( l <= r ) {
        m = (l+r)/2;
        if ( !check(m) ) {
            l = m+1;
            ans = m;
        }
        else r = m-1;
    }

    cout << ans;
}
