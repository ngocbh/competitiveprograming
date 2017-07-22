#include <bits/stdc++.h>
const long N = 100000 + 10;
using namespace std;
typedef long long LL;
LL x, y, m;
LL ans;
LL solve(LL x, LL y)
{
    LL res = 0;
    while ( x < m && y < m ) {
        ++res;
        if ( x > y ) swap(x,y);
        x += y;
        if ( res > N ) return -1;
    }
    return ans + res;
}
int main()
{  // freopen("P156SUMF.inp","r",stdin);
    cin >> x >> y >> m;
    if ( x >= m || y >= m ) {
        cout << 0;
        return 0;
    }
    if ( x > y ) swap(x,y);
    if ( x < 0 && y > 0 ) {
        LL tg;
        tg = -x / y;
        x = x + tg*y;
        ans += tg;
    }
    //cout << x << " " << y << " " << ans << endl;
    cout << solve(x,y);
}
