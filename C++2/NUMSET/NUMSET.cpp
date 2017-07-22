#include <bits/stdc++.h>

const long N = 30;
using namespace std;
int a[N], f[N][N], sum, ans = 0, n;
set <int> S;
int main()
{   freopen("NUMSET.inp","r",stdin);
    string s;
    cin >> s; n = s.size();
    for (int i = 0; i < s.size(); i++)
        a[i+1] = s[i] - '0', sum += a[i+1];

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++){
            if ( i == 1 && j == n ) continue;
            for (int o = i; o <= j; o++)
                f[i][j] += a[o];
                if ( f[i][j] % 3 == sum % 3 ) ++ans;
        }
    cout << ans;



}
