#include <bits/stdc++.h>
const long N = 10000 + 10;
using namespace std;
typedef long long LL;
LL t, n, a[N], f[N];
int main()
{
   // freopen("LINFRI.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        f[1] = a[1];
        for (int i = 2; i <= n; i++)
            f[i] = max(f[i-2]+a[i],f[i-1]);
        cout << f[n] << endl;
    }
}
