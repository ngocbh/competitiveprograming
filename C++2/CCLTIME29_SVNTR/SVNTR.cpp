#include <bits/stdc++.h>

const long N = 150 + 10;
using namespace std;
typedef long long LL;

int n, m, t, S, ans;
LL a[N][N], sum[N][N], b[N];

void solve()
{
    sort(b+1,b+m+1);

    for (int i = 0; i < m; i++) {
        int c = upper_bound(b+1,b+m+1,b[i]+S) - b - 1;
        if ( c == 0 ) continue;
        ans += c - i;
    }
}

int main()
{   freopen("SVNTR.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
        memset(a,0,sizeof a);
        cin >> n >> m >> S;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        ans = 0;
        memset(sum,0,sizeof sum);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];;
            }

        for (int i = 1; i <= n; i++)
            for (int ii = i; ii <= n; ii++) {
                memset(b,0,sizeof b);
                for (int j = 1; j <= m; j++)
                    b[j] = sum[ii][j] - sum[i-1][j];

                solve();
            }

        cout << ans << endl;
    }

}
