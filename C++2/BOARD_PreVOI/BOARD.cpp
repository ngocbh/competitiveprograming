#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

const long N = 400 + 10;

int n, m;
int a[N][N], ca[1000010];

bool check(int x,int y,int u,int v)
{
    bool ok = true;
    for (int i = x; i <= u; i++)
        for (int j = y; j <= v; j++) {
            ++ca[a[i][j]];
            if ( ca[a[i][j]] == 2 )
                ok = false;
        }

    for (int i = x; i <= u; i++)
        for (int j = y; j <= v; j++) {
            --ca[a[i][j]];
        }

    return ok;
}

int main()
{
    //freopen("BOARD.inp","r",stdin);
    //freopen("BOARD.out","w",stdout);

    cin >> m >> n;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];

    int ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            int prev = 0;
             for (int c = 1; c <= m; c++) {
                int x = 0;
                for (int k = i; k <= j; k++) {
                    prev = max(prev,ca[a[c][k]]);
                    ca[a[c][k]] = c;
                }
                ans = max(ans,(c - prev) * ( j - i + 1) );
             }
             for (int c = 1; c <= m; c++)
                for (int k = i; k <= j; k++)
                    ca[a[c][k]] = 0;
        }

    cout << ans;
}
