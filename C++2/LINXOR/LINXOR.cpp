#include <bits/stdc++.h>

const long N = 1000 + 10;

using namespace std;
int t,n, a[N],sum;
int main()
{  // freopen("LINXOR.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
        if ( sum %  n != 0 ) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += abs(a[i] - sum/n);
        cout << ans << endl;
    }
}
