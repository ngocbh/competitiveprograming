#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
int n, t, k;
int f[4][N];
string a[4];
int main()
{   //freopen("D.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
        cin >> n >> k;

        for (int i = 1; i <= 3; i++)
            cin >> a[i], a[i] = '.' + a[i];

        memset(f,false,sizeof f);
        for (int i = 1; i <= 2*n+1; i++)
            for (int j = 1; j <= 3; j++) a[j] = a[j] + '.';
        for (int i = 1; i <= 3; i++)
            if ( a[i][1] == 's' ) f[i][1] = true;


        for (int i = 4; i <= 3*n+1; i++) {
            for (int j = 1; j <= 3; j++) {
                if ( a[j][i] != '.' ) continue;

                for (int o = -1; o <= 1; o++) {
                    if ( o + j <= 3 && o + j >= 1 && a[j][i-2] == '.' && a[j+o][i-2] == '.' ) {
                            f[j][i] = f[j][i] | f[j+o][i-3];
                    }
                }
            }
        }

        if ( f[1][3*n+1] || f[2][3*n+1] || f[3][3*n+1] ) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

}
