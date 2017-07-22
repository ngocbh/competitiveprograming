#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
int n, a[N], ans;
set <int> s;
int main()
{   //freopen("HARA.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans = n;
    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++)
            if ( a[i] == a[j] ) {
                    bool ok = true;
                    for (int o = i; o <= j; o++)
                        if ( a[o] < a[i]) {
                            ok = false;
                            break;
                        }
                    if ( ok ) --ans;
            }
    cout << ans;
}
