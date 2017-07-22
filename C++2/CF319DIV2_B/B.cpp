#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
typedef long long LL;
int n, m;
int a[N];
LL suma[N], ca[N];
bool f[1001][1001];
int main()
{
    //freopen("B.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = a[i] % m;
            ++ca[a[i]];
    }
    if ( ca[0] > 0 ) {
        cout << "YES";
        return 0;
    }
    for (int i = 0; i <= m; i++) {
            if ( ca[i] ) {
                for (int j = 1; j <= ca[i]; j++)
                    f[i][j*i%m] = true;
            }
    }
    for (int i = 2; i <= m; i++) {
            if ( f[i][0] ) {
                cout << "YES";
                return 0;
            }
            for (int j = 0; j <= m; j++) {
                int x = j;
                    for (int k = 0; k <= ca[i]; k++) {
                        if ( x < 0 ) x += m;
                        if ( f[i-1][x] )
                        f[i][j] = f[i-1][x];
                       // if ( f[i][x] )
                       // f[i][j] = f[i][x];
                        if ( f[i][j] == true ) break;
                        x = x - i;
                    }
                if ( f[i-1][j] == true )
                f[i][j] = f[i-1][j];

            }
    }
   // for (int i = 1; i <= m; i++)  {
    //for (int j = 0; j <= m; j++) cout << f[i][j] << " "; cout << endl; }
    if ( f[m][0] ) cout << "YES";
    else
    cout << "NO";
}
