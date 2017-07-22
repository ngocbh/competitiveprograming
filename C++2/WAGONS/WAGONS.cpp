#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n;
int a[N], f[N], b[N], res[N];
stack <int> s;
int main()
{   freopen("WAGONS.inp","r",stdin);
    freopen("WAGONS.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[n] = a[n];
    for (int i = n-1; i > 0; i--) f[i] = min(f[i+1],a[i]);

    int sz = 0;
    s.push(a[1]);
    for (int i = 2; i <= n; i++) {
            while ( !s.empty() && s.top() <= f[i] )
                {
                    res[++sz] = s.top();
                    s.pop();
                }
        s.push(a[i]);
    }

    while ( !s.empty() ) res[++sz] = s.top(), s.pop();

    for (int i = 1; i <= n; i++) cout << res[i] << " ";
}
