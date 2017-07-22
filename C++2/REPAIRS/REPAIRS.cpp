#include <bits/stdc++.h>

const long N = 100000 + 10;
const long oo = (int) 1e9 + 7;
using namespace std;
int n, ans = 0;
int a[N];
int main()
{   freopen("REPAIRS.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n+1] = oo;
    for (int i = 1; i <= n; i++) if ( a[i] != a[i-1] ) ++ans;

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int p, c, cc;
        cin >> p >> c;
        if ( a[p] == c ) continue;
        cc = a[p];
        a[p] = c;
        if ( a[p] != a[p-1] && a[p-1] == a[p+1] ) ans += 2;
        if ( a[p] == a[p-1] && a[p-1] == a[p+1] ) ans -= 2;
        if ( a[p] != a[p-1] && a[p-1] != a[p+1] && a[p+1] != a[p] && ( cc == a[p-1] || cc == a[p+1] ) ) ans += 1;
        if ( ( a[p] == a[p-1] || a[p] == a[p+1] ) && cc != a[p+1] && a[p-1] != cc && a[p-1] != a[p+1] ) ans -= 1;
        if ( p == n && a[p] == a[p-1] ) ans -= 1;
        if ( p == 1 && a[p] == a[p+1] ) ans -= 1;
        cout << ans << endl;
    }

}
