#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
int n, t, a, b, m2[N];
int kt(int a)
{
    for (int i = 0; i <= 30; i++)
        if ( m2[i] == a ) return 1;
    return 0;
}
int main()
{   //freopen("COOKMACH.inp","r",stdin);
    cin >> t;
    m2[0] = 1;
    for (int i = 1; i <= 30; i++) m2[i] = m2[i-1] * 2;
    while ( t-- ) {
        cin >> a >> b;
        int ans = 0;
        while ( !kt(a) ) a /= 2,++ans;
        while ( a > b ) a /= 2,++ans;
        while ( a < b ) a *= 2,++ans;
        cout << ans << endl;
    }

}
