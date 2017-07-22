#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;
int x, p , q, a, b, n , c;
int main()
{   freopen("QUEUE.inp","r",stdin);
    freopen("QUEUE.out","w",stdout);
    cin >> x >> n >> c;

    int res = x, t = 0, q = x, tt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        q -= a-t;
        if ( q < 0 ) q = 0;
        if ( res >= q ) {
            res = q;
            tt = a;
        }
        q += b;
        t = a;
    }
    q -= c - t;
    if ( q < 0 ) q = 0;
    if ( res >= q ) {
            res = q;
            tt = c;
    }

    cout << tt << " " << res << endl;
}
