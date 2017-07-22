#include <bits/stdc++.h>

const long N = 1000000 + 10;
const long oo = (long) (1e9+7);
using namespace std;
int n;
int a[N], h[N], s[N], res[N];
int main()
{   freopen("FROGS.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> h[i];

    s[0] = oo;
    int k = 0;
    for (int i = n; i > 0; i--) {
        while ( a[i] > s[k] ) --k;

        s[++k] = a[i];

        if ( k - h[i] <= 0 ) res[i] = -1;
        else    res[i] = s[k-h[i]];
    }

    for (int i = 1; i <= n; i++) cout << res[i] << " ";
}
