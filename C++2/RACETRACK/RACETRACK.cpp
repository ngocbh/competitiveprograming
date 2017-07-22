#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n, k;
int main()
{   freopen("RACETRACK.inp","r",stdin);
    freopen("RACETRACK.out","w",stdout);
    cin >> n >> k;

    if ( k == 1 || k > n || n == k+1 || n % 2 == 1 ) {
        cout << -1;
        return 0;
    }

    for (int i = 1; (1<<i) <= n; i++) {
        if ( k == 3 && (1<<i) == n ) {
            cout << -1;
            return 0;
        }
    }

    if ( k == 3 ) {

        int n2 = n/2,t;
        cout << n2 << " ";
        for (int i = 0; i <= 20; ++i)
        if ( n2 & ( 1 << i ) ) {
            t = i;
            break;
        }
        cout << " " << n2 - (1 << t) << " " << (1<<t);
        return 0;
    }

    if ( k > 3 && k % 2 == 1 ) {
        cout << 1 << " " << 2 << " " << 3 << " ";
        k -= 3;
        n -= 6;
    }
    for (int i = 1; i <= k-2; i++) cout << 1 << " ", --n;
    cout <<  n/2 << " " << n/2;

}
