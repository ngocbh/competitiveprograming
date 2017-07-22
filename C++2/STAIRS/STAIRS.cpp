#include <bits/stdc++.h>

const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
using namespace std;
typedef long long LL;
LL n, ans = 0, cur;
LL p[N];
string x, y;

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = (p[i-1]*10) % MOD;

    for (int i = 0; i < x.size(); i++) ans = (ans*10 + x[i] - '0') % MOD;
    cur = ans;
}

void solve()
{
    LL l = y.size();
    LL res = cur, rem = 0;
    for (int i = 0; i < l; i++)  {
        LL m = y[i] - x[i] - rem;

        if ( m < 0 ) m += 10, rem = 1;
        else rem = 0;

        ans = (ans + res*m + p[i]*m*(m+1)/2) % MOD;
        res = (res + m*p[i]) % MOD;
    }
    cur = res;
}

int main()
{
    freopen("STAIRS.inp","r",stdin);
    freopen("STAIRS.out","w",stdout);

    cin >> n;
    cin >> x;

    init();
    reverse(x.begin(),x.end());

    for (int i = 2; i <= n; i++) {

        cin >> y;
        reverse(y.begin(),y.end());
        y = y + "0";
        while ( x.size() < y.size() ) x = x + "0";

        solve();
        x = y;
    }

    cout << ans;

}
