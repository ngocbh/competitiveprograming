#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
int n, ans = 0;
int a[N], f[N];
int main()
{   //freopen("BALONI.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 0; i--) {
        if ( f[a[i]-1] ) {
            --f[a[i]-1];
            ++f[a[i]];
        } else {
            ++ans;
            ++f[a[i]];
        }
    }
    cout << ans;
}
