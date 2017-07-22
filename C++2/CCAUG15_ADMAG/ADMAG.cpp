#include <bits/stdc++.h>

const long N = 100000 +10;
using namespace std;
typedef long long LL;
LL n;
LL t, ans, f[N], a[N];
void solve(LL n)
{
LL    sl = 0;
    f[0] = 1;
    while ( f[sl] <= n ) {
        LL x;
        x = f[sl] + f[sl-1];
        f[++sl] = x;
    }
    cout << sl - 1 << endl;

}
int main()
{  // freopen("ADMAG.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
        cin >> n;
        solve(n);
    }
}
