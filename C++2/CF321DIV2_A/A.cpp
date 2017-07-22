#include <bits/stdc++.h>

const long N = 100000 + 10;

using namespace std;
int n;
int a[N],f[N];
int ans;

int main()
{
   // freopen("A.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if ( a[i] >= a[i-1] ) f[i] = f[i-1] + 1;
        else f[i] = 1;
        ans = max(ans, f[i]);
    }
    cout << ans ;
}
