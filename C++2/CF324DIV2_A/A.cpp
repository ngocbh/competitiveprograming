#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
int n, t;
int main()
{      //freopen("A.inp","r",stdin);
       cin >> n >> t;
       if ( n == 1 && t == 10 ) {
        cout << -1;
        return 0;
       }
       if ( t == 10 ) cout << 1; else
        cout << t % 10;
            for (int i = 1; i < n; i++) cout << 0;
            return 0;

}
