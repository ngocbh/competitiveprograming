#include <bits/stdc++.h>

const long N = 1000 + 10;
const long MOD = 1000003;

using namespace std;

int n;
int f[N][N];
char a[N][N];
char s[N];

int main()
{   freopen("MAGIC.inp","r",stdin);
    freopen("MAGIC.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%s", a[i] + 1);

    scanf("%s", s+1);

    if ( a[1][1] == s[1] ) f[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if ( i == 1 && j == 1 ) continue;
            if ( a[i][j] == s[i+j-1] ) {
                f[i][j] = (f[i-1][j] + f[i][j-1]) % MOD;
            }
        }

    cout << f[n][n];
}
