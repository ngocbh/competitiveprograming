#include <bits/stdc++.h>

const long N = 1000000 + 100;
using namespace std;
int n;
typedef long long LL;
LL a[N], f[N], pow2[20];
int main()
{   //freopen("C.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i =1 ; i <= n; i++) cin >> a[i], ++f[ a[i]];

    LL ans = 0;
    for (int i = 0; i < N; i++) {
        f[i+1] += (f[i]/2);
        ans += f[i] % 2;
    }
    cout << ans;
}
