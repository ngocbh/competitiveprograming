#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
int n, k;
int a[N], c[N];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ++c[a[i]];
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        if ( c[i] < n/k ) ans += - c[i] + (n/k);
    }
    cout << ans;
}
