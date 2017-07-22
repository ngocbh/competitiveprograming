#include <bits/stdc++.h>

const long N = 100000 + 10;

using namespace std;
typedef long long LL;
int n, v1, v2, k, m;
LL s;
int x[N], a[N];

int main()
{
    freopen("CHASE.inp","r",stdin);
    freopen("CHASE.out","w",stdout);
    cin >> n >> k;
    cin >> v1 >> v2;
    cin >> s;
    m = n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> a[i];

    for (int i = 1; i <= n; i++) if ( x[i] >= s ) {
        m = i;
        break;
    }

    if ( s == 0 ) {
        cout << 0 ;
        return 0;
    }
    if ( v1 >= v2 ) {
        cout << "inf";
        return 0;
    }

    priority_queue<int> qu;
    qu.push(0);
    LL d = 0;
    while ( k-- ) {

            for (int &i = m; i <= n; i++) {
                if ( (double)(x[i] - s)/v1 >= (double)(x[i] + d) / v2 ) break;
                qu.push(a[i]);
            }
            if ( !qu.empty() ) d += 1LL*v2*qu.top();
            else break;
            qu.pop();
    }
    double ans = (double) (d+s) / (v2-v1);
    cout << fixed << setprecision(10) << ans;

}
