#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
int t, n, w[N];
string s1, s2;
int main()
{   //freopen("WDTBAM.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> t;
    while ( t-- ) {
        int corect = 0;
        cin >> n;
        cin >> s1;
        cin >> s2;
        for (int i = 0; i < n; i++)
            if ( s1[i] == s2[i] ) ++corect;

        for (int i = 0; i <= n; i++) cin >> w[i];

        int ans = 0;
        if ( corect == n ) ans = max(ans,w[n]);
        else
        for (int i = 0; i <= corect; i++)  ans = max(ans,w[i]);
        cout << ans << endl;
    }

}
