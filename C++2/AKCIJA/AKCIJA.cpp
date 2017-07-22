#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
int n;
int a[N];
int main()
{   //freopen("AKCIJA.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1,a+n+1);
    LL ans = 0, t = n;
    for (int i = n; i > 0; i--) {
        if ( t - 2 < i && t >= 3 ) {
                ans += a[i];
                continue;
        }
        if ( i == t-2 && t >= 3 ) {
            t = i-1;
            continue;
        }
        ans += a[i];
    }
    cout << ans ;

}
