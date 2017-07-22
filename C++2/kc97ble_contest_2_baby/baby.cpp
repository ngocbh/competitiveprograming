#include <bits/stdc++.h>

using namespace std;

const long N = 17;

int n, ans ;
int a[N], b[N], x[N], ca[N], f[N][1<<16 + 1];

void repair(int &x, int y)
{
    if ( x > y ) x = y;
}

int main()
{
    //freopen("baby.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    while ( 1 ) {
        cin >> n;
        if ( n == 0 ) return 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];

        int mask = (1<<n)-1;

        f[0][0] = 0;
        vector <int> qw;
        for (int i = 1; i <= mask; i++) {
        int s = __builtin_popcount(i);
            qw.clear();
            for (int j = 1; j <= n; j++)
                if ( (i>>(j-1))&1 )
                    qw.push_back(j);
            for (int j, cj = 0; cj < qw.size(); cj++) {
                j = qw[cj];
                f[j][i] = (int)1e9;
                for (int k, ck = 0;ck < qw.size(); ck++) {
                        k = qw[ck];
                        if ( k == j ) continue;
                        repair(f[j][i],f[k][(~(1<<(j-1))) & i] + abs(j-s) + abs(a[j]-b[s]));
                }
                    if ( s == 1 )
                        repair(f[j][i],f[0][0] + abs(j-s) + abs(a[j]-b[s]));
                }
        }

        int ans = (int) 1e9;
        for (int i = 1; i <= n; i++) repair(ans,f[i][mask]);
        cout << ans << endl;
    }
}
