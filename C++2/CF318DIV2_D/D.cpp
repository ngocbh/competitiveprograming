#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n, a[N], l[N], r[N];
int main()
{  // freopen("D.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) l[i] = min(a[i] , l[i-1] + 1);
    for (int i = n; i >= 1; i--) r[i] = min(a[i] , r[i+1] + 1);
    int ans = -1;
    for (int i = 1; i <= n; i++) ans = max(ans, min(l[i],r[i]) );
    cout << ans ;

}
