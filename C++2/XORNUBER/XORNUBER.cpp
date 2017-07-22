#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL t, n;
LL a[40];
int main()
{
    //freopen("XORNUBER.inp","r",stdin);
    a[0] = 1;
    for (int i = 1; i <= 31; i++) a[i] = a[i-1]*2;
    cin >> t;
    while ( t-- ) {
        cin >> n;
        if ( n == 1 ) { cout << 2 << endl; continue; }
        LL ans = -1;
        for (int i = 1; i <= 31; i++) {
            if ( n == a[i]-1 ) ans = a[i-1] - 1;
        }
        cout << ans << endl ;
    }
}
