#include <bits/stdc++.h>

const long N = 300000 + 5;
const long MOD = 1000000007;
using namespace std;

typedef long long LL;
typedef pair <int,int> ii;

struct point{
    int x,y;
};

int n;
int dp[N], suma[N];
point a[N];

vector <point> L[N];

bool cmp(point a,point b)
{
    return ( a.x < b.x || ( a.x == b.x && a.y > b.y) ) ;
}

int main()
{
    freopen("MCONVOI.inp","r",stdin);
    //freopen("MCONVOI.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a+1,a+n+1,cmp);
    a[0].y = MOD;
    int cn = 0; point ans = {0,0};
    for (int i = 1; i <= n; i++)
    {
            int l = 0, r = cn, u = 0, v = -1;
            while ( l <= r ) {
                int m = (l + r + 1) / 2;
                if ( m == 0 ) { l = 1;continue; }
                if ( a[L[m].back().x].y < a[i].y )
                    l = m+1, u = m;
                else r = m-1;
            }

            l = 0, r = L[u].size()-1;
            while ( l <= r ) {
                int m = (l + r + 1)/2;
                if ( a[L[u][m].x].y >= a[i].y )
                    l = m+1, v = m;
                else r = m - 1;
            }
            point mypoint;
            if ( u == 0 ) {
                suma[u+1] += 1;
                mypoint = {i,suma[1]};
                L[1].push_back(mypoint);
            } else {
                int uv;
                if ( v == -1 ) uv = suma[u];
                else    uv = suma[u] - L[u][v].y;
                if ( uv <= 0 ) uv += MOD;
                suma[u+1] = (uv + suma[u+1]) % MOD;
                if ( L[u+1].size() > 0 )
                uv = ( L[u+1].back().y + uv ) % MOD;
                mypoint = {i,uv};
                L[u+1].push_back(mypoint);
            }
            if ( u == cn ) ++cn;
    }
    cout << cn << endl << L[cn].back().y;

}

