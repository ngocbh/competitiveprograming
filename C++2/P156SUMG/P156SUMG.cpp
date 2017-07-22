#include <bits/stdc++.h>

const long N = 3000 + 10;
const long long oo = 1000000000 + 7;
using namespace std;
typedef long long LL;
LL n, ans;
LL a[N];
int main()
{   //freopen("P156SUMG.inp","r",stdin);
    cin >> n;
    ans = -oo*oo;
    ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        LL l,r,res,MIN = 0, MAX = -oo*oo;
        l = i;
        r = n;
        res = 0;
        while ( l < r ) {
            res += a[l]*a[r];
            MAX = max(res,MAX);
            ans = max(ans , MAX - MIN );
            MIN = min(res,MIN);
            ++l;--r;
        }
    }
    for (int i = 1; i <= n; i++) {
        LL l,r,res,MIN = 0, MAX = -oo*oo;
        l = 1;
        r = i;
        res = 0;
        while ( l < r ) {
            res += a[l]*a[r];
            MAX = max(res,MAX);
            ans = max(ans , MAX - MIN );
            MIN = min(res,MIN);
            ++l;--r;
        }
    }
    cout << ans;
}
