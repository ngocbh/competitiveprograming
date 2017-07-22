#include <bits/stdc++.h>

using namespace std;

const long N = 200 + 10;
const long long oo = 1000000000 + 7;
typedef long long LL;

int n,m,a,b,k;
LL c[N][N], ht[N][N], hcn[N][N], h[N][N], sum[N][N];

void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + c[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            h[i][j] = h[i][j-1] + c[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            hcn[i][j] = sum[i+a-1][j+b-1] - sum[i+a-1][j-1] - sum[i-1][j+b-1] + sum[i-1][j-1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if ( i - k > 0 && i + k <= n && j - k > 0 && j + k <= m ) {
                for (int o = i-k; o <= i+k; o++) {
                    int hk = k - abs(o-i);
                    ht[i][j] += h[o][j+hk] - h[o][j-hk-1];
                }
            }
        }
}

bool checkin(int x,int y,int u,int v)
{
    if ( x+a-1 > n || y+b-1 > m || u-k < 1 || u+k > n || v-k < 1 || v+k > m ) return false;
    if ( u-k >= x && u-k <= x+a-1 && v >= y && v <= y+b-1 ) return false;
    if ( u+k >= x && u+k <= x+a-1 && v >= y && v <= y+b-1 ) return false;
    if ( u >= x && u <= x+a-1 && v-k >= y && v-k <= y+b-1 ) return false;
    if ( u >= x && u <= x+a-1 && v+k >= y && v+k <= y+b-1 ) return false;
    if ( abs(x-u) + abs(y-v) <= k ) return false;
    if ( abs(x-u) + abs(y+b-1-v) <= k ) return false;
    if ( abs(x+a-1-u) + abs(y-v) <= k ) return false;
    if ( abs(x+a-1-u) + abs(y+b-1-v) <= k ) return false;
    return true;
}

bool checkht(int x,int y,int u,int v)
{
    if ( abs(x-u) + abs(y-v) <= k ) return false;
    return true;
}

bool checkhcn(int x,int y,int u,int v)
{
    if ( x >= u && x <= u+a-1 && y >= v && y <= v+b-1 ) return false;
    return true;
}

bool check(int x,int y,int u,int v)
{
    if ( x+a-1 > n || y+b-1 > m || u-k < 1 || u+k > n || v-k < 1 || v+k > m ) return false;

    bool ok = true;
    for (int i = x; i <= x+a-1; i++) {
      if ( !checkht(i,y,u,v) || !checkht(i,y+b-1,u,v) )  ok = false;
    }
    for (int i = y; i <= y+b-1; i++) if ( !checkht(x,i,u,v) || !checkht(x+a-1,i,u,v) )  ok = false;
    if ( !checkht(x,y,u,v) ) ok = false;
    if ( !checkhcn(u,v,x,y) ) ok = false;
    return ok;
}

int main()
{
    //freopen("VOLAND.inp","r",stdin);
    cin >> n >> m >> a >> b >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];

    init();
    LL ans = -oo*oo;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int ci = 1; ci <= n; ci++)
                for (int cj = 1; cj <= m; cj++) {
                    if ( !checkin(i,j,ci,cj) ) continue;
                    if ( !check(i,j,ci,cj) ) continue;
                    ans = max(ans,hcn[i][j] + ht[ci][cj] );
                }

    if ( ans == -oo*oo ) {
        cout << "no solution";
    }
    else cout << ans;
}


