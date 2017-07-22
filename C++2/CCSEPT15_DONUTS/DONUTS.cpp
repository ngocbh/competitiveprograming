#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n, t, m;
int a[N];
int main()
{   //freopen("DONUTS.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
            cin >> n >> m;
            for (int i = 1; i <= m; i++) cin >> a[i];
            sort(a+1,a+m+1);

            int ans = 0, cm = m;
            for (int i = 1;  i <= m; i++) {
                    if ( ans + a[i] == cm - 2 ) {
                            cout << ans + a[i] << endl;
                            break;
                    }
                    if ( ans + a[i] >= cm - 1 ) {
                            cout << cm - 1 << endl;
                            break;
                    }
                    ans += a[i];
                    --cm;
            }
    }

}
