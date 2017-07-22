#include <bits/stdc++.h>

const long N = 10000;
using namespace std;
int n;
int main()
{   //freopen("A.inp","r",stdin);
    cin >> n;
    int ans = 0;
    while ( n > 0 ) {
        int x = 1;
        while ( x*2 <= n ) x*=2;
        ++ans;
        n -= x;
    }
    cout << ans;

}
