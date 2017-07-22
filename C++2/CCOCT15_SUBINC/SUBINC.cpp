#include <bits/stdc++.h>

const long N = 100000 + 10;
const long oo = (int)(1e9+7);

using namespace std;
typedef long long LL;

int t, n;
int a[N];

LL calc(int n)
{
    return (1LL*n*(n+1)) / 2;
}

int main()
{   //freopen("SUBINC.inp","r",stdin);
    ios::sync_with_stdio(0);

    cin >> t;
    while ( t-- ) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n+1] = 0;
    int prev = 1;
    LL ans = 0;
    for (int i = 1; i <= n+1; i++) {
        if ( a[i] >= a[i-1] ) continue;
        if ( a[i] < a[i-1] ) ans += calc(i - prev);
        prev = i;
    }

    cout << ans << endl;
    }
}
