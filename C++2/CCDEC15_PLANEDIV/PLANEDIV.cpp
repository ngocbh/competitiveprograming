/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;
typedef pair <ii,ii> iii;

int n, g;
int a[N], b[N], c[N], cs[N], a1[N], b1[N];
iii f[N];

int gcd(int a,int b)
{
    if ( a == 0 && b == 0 ) return 1 ;
    if ( a == 0 ) return b;
    if ( b == 0 ) return a;
    int m = a, n = b, r;
    while ( n != 0 ) {
        r = m % n;
        m = n;
        n = r;
    }
    return abs(m);
}

int main()
{
    //freopen("PLANEDIV.inp","r",stdin);
    //freopen("PLANEDIV.out","w",stdout);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while ( t-- ) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> a[i] >> b[i] >> c[i];
                int g = gcd(a[i],b[i]);
                f[i].first = ii(-a[i]/g,b[i]/g);
                if ( f[i].first.second < 0 ) f[i].first.first *= -1, f[i].first.second *= -1;
                g = gcd(c[i],b[i]);
                f[i].second = ii(-c[i]/g,b[i]/g);
                if ( f[i].second.second < 0 ) f[i].second.first *= -1, f[i].second.second *= -1;
                if ( b[i] == 0 ) {
                        f[i].first = ii(1,0);
                        f[i].second = ii(c[i]/gcd(c[i],a[i]),a[i]/gcd(c[i],a[i]));
                        if ( f[i].second.second < 0 ) f[i].second.first *= -1, f[i].second.second *= -1;
                }
                //if ( a[i] == 0 ) f[i].first = ii(0,oo), f[i].second = ii(c[i]/gcd(-c[i],b[i]),b[i]/gcd(c[i],b[i]));
        }

        sort(f+1,f+n+1);
        int ans = 1, cur = 0;

        for (int i = 1; i <= n; i++) {
            if ( f[i].first == f[i-1].first ) {
                if ( f[i].second != f[i-1].second ) ++cur;
            }
            else {
                ans = max(ans,cur);
                cur = 1;
            }
        }

        ans = max(ans,cur);

        cout << ans << endl;
    }

}
