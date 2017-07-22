#include <bits/stdc++.h>

using namespace std;

const long N = 200 + 10;
const long MOD = 111539786;

int n, k;
int a[N][N], f[N][N], jum[N][100];
string s[12];


int check(int x,char c)
{
    string ss = "";
    ss = s[1].substr(1,x);

    int j = x + 1;
    while ( true )
    {
        if ( ss+c == s[1].substr(1,j) ) return j;
        ss.erase(0,1);
        --j;
        if ( j == 0 ) return 0;
    }
}

void solve_sub2()
{
    int q = s[1].size()-1;

    for (int i = 0; i < q; i++)
    {
        for (int c = '0'; c <= '1'; c++)
            jum[i][c] = check(i,c);
    }
    memset(f,0,sizeof f);

    f[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
            for (int k = '0'; k <= '1'; k++)
                f[i+1][jum[j][k]] = ( f[i+1][jum[j][k]] + f[i][j] ) % MOD;
    }
    long long ans = 0;
    for (int j = 0; j < q; j++) ans = (ans + f[n][j]) % MOD;
    cout << ans;
}

int main()
{
    freopen("ASTR2.inp","r",stdin);
    freopen("ASTR2.out","w",stdout);

    scanf("%d %d ", &n, &k);

    for (int i = 1; i <= k; i++) {
        cin >> s[i];
        s[i] = '0' + s[i];
    }

    if ( k == 1 ) solve_sub2();
}
