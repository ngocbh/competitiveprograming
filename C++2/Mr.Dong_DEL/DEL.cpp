/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 11;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n;
LL k;
LL a[N];

bool mutil(LL a,LL b)
{
    while ( b > 0 ) {

    }
}

bool check(LL m)
{
    int mask = (1<<n)-1;
    LL res = 0, bcnn = 1;
    for (int x = 1; x <= mask; x++) {
        int sl = 0;
        for (int i = 1; i <= n; i++) {
            if ( (x>>(i-1))&1 == 1 ) {
                if ( sl == 0 ) {
                    bcnn = a[i];
                }
                else {
                    bcnn = bcnn/__gcd(bcnn,a[i]);
                    if ( !mutil(bcnn,a[i]) ) return true;
                    bcnn = bcnn*a[i];
                }
                ++sl;
            }
        }
        if ( sl % 2 == 1 ) res += m/bcnn;
        else res -= m/bcnn;
    }

    if ( m - res < k ) return true;
    else return false;
}

int main()
{
    freopen("DEL.inp","r",stdin);
    //freopen("DEL.out","w",stdout);
    int t;
    cin >> t;
    while ( t-- ) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        LL l = 1, r = oo*oo, ans = 0, m;
        while ( l <= r ) {
            m = (l+r)/2;
            if ( check(m) ) {
                l = m+1;
                ans = m;
            }
            else r = m-1;
        }

        cout << ans+1 << endl;
    }

}
