#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
int t;
LL k;
int main()
{   //freopen("CHUSO.inp","r",stdin);
    cin >> t;
    while ( t -- ) {
            cin >> k;
            LL l = 0, r = 2000000000 + 7, m;
            while ( r - l > 1 ) {
                    m = ( l + r ) / 2;
                    if ( ((m * ( m + 1 )) / 2 ) > k ) r = m;
                    else l = m;
            }
            k = k - ((l * ( l + 1 )) / 2 );
            if (k == 0 ) k = l;
            cout << k % 10 << endl;
    }

}
