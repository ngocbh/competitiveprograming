#include <bits/stdc++.h>

const long N = 1000;
using namespace std;
int t, s, p, q , ans = 0;
int main()
{   //freopen("A.inp","r",stdin);
    cin >> t >> s >> q;
    ++ans;
    while ( s < t ) {
        if (  p + q > s + q - 1 ) {
            ++ans;
            p = 0;
            continue;
        }
        p += q;
        s += q - 1;
    }
    cout << ans ;
}
