#include <bits/stdc++.h>

using namespace std;

const long N = 5000 + 10;
const long long MOD = 1000000000 + 7;

typedef long long LL;
LL n, m, k, ans;
LL f[N][N], sum[N][N], Hash[N], Pow[N];
short  ca[N][N];
char s[N];

LL GetHash(int i,int j)
{
    return ( Hash[j] - Hash[i-1]*Pow[j-i+1] + MOD*MOD ) % MOD;
}

bool check(int x, int y, int u, int v)
{
    int p = 0;
    for (int l = 0, r = y - x + 1; l <= r; )
    {
        int m = (l + r) / 2;
        if (GetHash(x, x + m - 1) == GetHash(u, u + m - 1)) p = max(p, m), l = m + 1;
            else r = m - 1;
    }
    if (p == y - x + 1) return 0;
    return s[x + p] > s[u + p];
}

int main()
{
    freopen("D.inp","r",stdin);
    cin >> n;
    scanf("%s", s+1);

    Pow[0] = 1;
    for (int i = 1; i <= n; i++) Pow[i] = (Pow[i-1]*107) % MOD;

    for (int i = 1; i <= n; i++) Hash[i] = (Hash[i-1]*107 + s[i] - '0') % MOD;

    /*for (int i = n; i >= 1; i--)
        for (int j = n-i; j >= 1; j--)
        {
            if ( s[i-j] < s[i] ) ca[i][j] = 2;
            if ( s[i-j] > s[i] ) ca[i][j] = 1;
            if ( s[i-j] == s[i] ) {
                if ( GetHash(i-j,i-1) == GetHash(i,i+j-1) ) ca[i][j] == 0;
                else ca[i][j] = ca[i-1][j];
            }
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            check[i+j-1][j] = ca[i][j];*/
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) sum[0][i] = 1;
        //for (int j = i; j <= n; j++) f[i][j] = 1, sum[i][j] = (sum[i][j-1] + f[i][j]) % MOD;


    for (int i = 0; i <= n; i++) f[0][0] = sum[0][i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        if (s[i - j + 1] != '0')
        {
            f[i][j] = sum[i - j][j - 1];
            if (i < 2 * j) f[i][j] = ( f[i - j][j] + f[i][j] ) % MOD;
                else if (check(i - j + 1, i, i - 2 * j + 1, i - j))
                    f[i][j] = (f[i - j][j] + f[i][j] ) % MOD;
        }
        for (int j = 1; j <= n; j++)
            sum[i][j] = (sum[i][j - 1] + f[i][j]) % MOD;
    }

    cout << sum[n][n];
}
