#include <bits/stdc++.h>

const long N = 10000;
using namespace std;
int n;
int main()
{   //freopen("DEMSO0.inp","r",stdin);
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        while ( x % 5 == 0 ) ++ans, x/=5;
    }
    cout << ans;
}
