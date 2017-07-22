#include <bits/stdc++.h>
#define x first
#define y second
const long N = 1000 + 10;
using namespace std;
typedef pair <int,int> ii;
typedef long long LL;

int m,n,k;
LL ans = 0;
int a[N][N];
ii M[N];

void solve_sub2()
{
    LL ans = 0;
    for (int r = 1; r <= min(m,n)-1;r++)
        for (int x = 1; x <= m-r; x++)
            for (int y = 1; y <= n-r; y++)
                for (int h = 0; h <= r-1; h++) {
                        ii A, B, C, D;
                        A.x = x; A.y = y+h;
                        B.x = x+h; B.y = y+r;
                        C.x = x+r; C.y = y+r-h;
                        D.x = x+r-h; D.y = y;
                        if ( !a[A.x][A.y] && !a[B.x][B.y] && !a[C.x][C.y] && !a[D.x][D.y] )
                            ++ans;
                }
    cout << ans;
}

bool check1(int u,int v,int h,int r)
{
    if ( u >= 1 && v - h >= 1 && u+r <= m && v+r-h <= n )
        return true;

    return false;
}

bool check2(int u,int v,int h,int r)
{
    if ( u-h < 1 || v-r < 1 || u+r-h > m || v > n ) return false;
    if ( a[u-h][v-r+h] ) return false;

    return true;
}

bool check3(int u,int v,int h,int r)
{
    if ( u-r < 1 || v-r+h < 1 || u > m || v+h > n ) return false;
    if ( a[u-r+h][v+h] ) return false;
    if ( a[u-r][v+2*h-r] ) return false;

    return true;
}

bool check4(int u,int v,int h,int r)
{
    if ( u-r+h < 1 || v < 1 || u+h > m || v+r > n ) return false;
    if ( a[u+h][v+r-h] ) return false;
    if ( a[u-r+2*h][v+r] ) return false;
    if ( a[u-r+h][v+h] ) return false;

    return true;

}

int main()
{
    freopen("SQUARES.inp","r",stdin);
    freopen("SQUARES.out","w",stdout);

    cin >> m >> n >> k;




    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        M[i] = ii(u,v);
        a[u][v] = 1;
    }

    //if ( m <= 100 && n <= 100 ) solve_sub2();

    for (int r = 1; r <= min(m,n)-1; r++)
        ans += (m-r)*(n-r)*r;

    for (int r = 1; r < min(m,n); r++)
        for (int i = 1; i <= k; i++)
            for (int h = 0; h < r; h++) {
                    int u, v;
                    u = M[i].x;
                    v = M[i].y;
                    if ( check1(u,v,h,r) ) --ans;
                    if ( check2(u,v,h,r) ) --ans;
                    if ( check3(u,v,h,r) ) --ans;
                    if ( check4(u,v,h,r) ) --ans;
                }
    cout << ans;
}
