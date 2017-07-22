#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const long N = 500 + 10;
const long MOD = 1000000000 + 7;

int n;
LL dp[N][N][2];
char a[N][N];

void add(LL &X,LL Y)
{
    X += Y;
    if ( X >= MOD ) X -= MOD;
}

int main()
{
    freopen("palpath.in","r",stdin);
    freopen("palpath.out","w",stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%s", a[i] + 1);

    int len = n+n-1;
    dp[1][n][1] = (a[1][1] == a[n][n]);

    LL ans = 0;

    for (int o = 2; o <= (len+1)/2; o++)
    {
        int cur = o % 2, prev = 1 - cur;

        for (int i = 1; i <= n; i++)
            for (int j = n; j >= i; j--)
            {
                int ci = o + 1 - i;
                int cj = len - o + 2 - j;
                dp[i][j][cur] = 0;

                if ( ci < 1 || ci > n || cj < 1 || cj > n || ci > cj ) continue;
                if ( a[ci][i] != a[cj][j] ) continue;

                add(dp[i][j][cur] , dp[i][j][prev]);
                add(dp[i][j][cur] , dp[i-1][j][prev]);
                add(dp[i][j][cur] , dp[i][j+1][prev]);
                add(dp[i][j][cur] , dp[i-1][j+1][prev]);
                if ( o == (len+1)/2 ) add(ans , dp[i][j][cur]);
                //cout << ci << " " << i << " " << cj << " " << j << " " << dp[i][j][cur] << endl;
            }
    }

    printf("%lld", ans);
}
