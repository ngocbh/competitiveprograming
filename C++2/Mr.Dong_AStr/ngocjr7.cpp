#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;
const long MOD = 111539786;
typedef long long LL;

int n, q;
string sq;
LL a[N], f[N][35];

int main()
{
    freopen("ASTR.inp","r",stdin);
    //freopen("ASTR.out","w",stdout);

    while ( true )
    {
        n = 0;
        cin >> n;
        if ( n == 0 ) break;
        cin >> sq;
        q = sq.size();

        LL h = 0;

        for (int i = 0; i < q; i++)
        {
            h = h*2 + sq[i] - '0';
        }

        memset(f,0,sizeof f);

        int mask = (1<<q) - 1;
        for (int i = 0; i <= min((1<<1)-1,mask); i++)
            if ( i != h ) f[q][i] = 1;

        for (int i = q+1; i <= n; i++)
        {
            for (int j = 0; j <= min((1<<i)-1,mask); j++)
            {
                int ij = ((j>>1)|(1<<(q-1)));
                if ( j == h && i >= q ) continue;
                f[i][j] = ( f[i-1][j>>1] + f[i-1][ij] ) % MOD;
            }
        }

        LL ans = 0;

        for (int i = 0; i <= mask; i++) ans = (ans + f[n][i] ) % MOD;
        cout << ans << endl;
    }
}

