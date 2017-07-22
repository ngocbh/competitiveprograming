#include <bits/stdc++.h>
#define x first
#define y second

const long N = 1000 + 10;
using namespace std;
typedef pair <double,double> ii;

int n, m, k;
int a[N][N];
bool ca[101][101][101][101];

bool check(int u1,int v1,int u2,int v2)
{
    ii mid;
    mid.x = (double)(u1 + u2) / 2;
    mid.y = (double)(v1 + v2) / 2;

    ii d1,d2;
    d1.x = mid.x + (v1 - mid.y);
    d1.y = mid.y + (u2 - mid.x);
    d2.x = mid.x + (v2 - mid.y);
    d2.y = mid.y + (u1 - mid.x);
    if ( d1.x != (int) d1.x ) return false;
    if ( d1.y != (int) d1.y ) return false;
    if ( d2.x != (int) d2.x ) return false;
    if ( d2.y != (int) d2.y ) return false;
    if ( a[(int)d1.x][(int)d1.y] && a[(int)d2.x][(int)d2.y] && !ca[(int)d1.x][(int)d1.y][(int)d2.x][(int)d2.y] ) {
            ca[(int)d1.x][(int)d1.y][(int)d2.x][(int)d2.y] = true;
            ca[(int)d2.x][(int)d2.y][(int)d1.x][(int)d1.y] = true;
            return true;
    }
    return false;
}

int main()
{   freopen("SQUARES.inp","r",stdin);
    freopen("SQUARES.out","w",stdout);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = 1;

    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 0;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int ii = 1; ii < i; ii++)
                for (int jj = 1; jj <= m; jj++) {
                    if ( a[i][j] && a[ii][jj] )
                    if ( check(i,j,ii,jj) ) ++ans, ca[i][j][ii][jj] = true, ca[ii][jj][i][j] = true;
                }

    cout << ans;

}
