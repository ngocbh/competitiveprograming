#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
int n;
LL a[N], p[N], _min = 100000;
int main()
{   //freopen("A.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> p[i];
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        _min = min(_min , p[i]);
        ans += _min*a[i];
    }
    cout << ans;
}
