#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;

LL n, k;
LL a[N];
int main()
{   freopen("ANTS.inp","r",stdin);
    freopen("ANTS.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        if ( a[i] < 0 ) {
            ans = max(ans,-a[i]);
        }   else {
            ans = max(ans,k-a[i]);
        }
    }
    cout << ans;

}
