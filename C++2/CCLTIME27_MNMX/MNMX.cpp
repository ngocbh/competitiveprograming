#include <bits/stdc++.h>

const long N = 50000 + 10;
using namespace std;
typedef long long LL;
int n, t, a[N];
int main()
{   //freopen("MNMX.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        int _min = N*2;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            _min = min(_min,a[i]);
        }
        LL ans;
        ans = 1LL*_min*(n-1);
        cout << ans << endl;
    }

}
