#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef pair <int,int> ii;
int n;
ii a[N];
int d[1][N], ca[N];
int main()
{   //freopen("B.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = i;

    memset(ca,true,sizeof ca);
    int ans = 0, nn = n, vt = 1, ht = 1;
    while ( nn > 0 ) {
        if ( vt == 1 ) {
            bool ok = true;

            for (int i = ht; i <= n; i++) {
                if ( n-nn >= a[i].first && ca[i] ) {
                    --nn;
                    ca[i] = false;
                    ok = false;
                    ht = i;
                    break;
                }
            }
            if ( ok ) vt = 2, ++ans;

        }   else {

            bool ok = true;

            for (int i = ht; i >= 1; i--) {
                if ( n-nn >= a[i].first && ca[i] ) {
                    --nn;
                    ca[i] = false;
                    ok = false;
                    ht = i;
                    break;
                }
            }

            if ( ok ) vt = 1, ++ans;
        }
    }
    cout << ans;
}
