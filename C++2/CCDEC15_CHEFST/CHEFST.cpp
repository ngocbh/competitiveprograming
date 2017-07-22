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

int main()
{
    //freopen("CHEFST.inp","r",stdin);
    //freopen("CHEFST.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while ( t-- ) {
        LL n1,n2,m;

        cin >> n1 >> n2 >> m;
        LL n = min(n1,n2);
        LL x = (LL) sqrt(2*n);
        LL s = x*x + x;
        if ( s > 2*n ) --x;
        s = x*x + x;
        if ( x < m ) {
            cout << max(n2,n1) - min(n2,n1) << endl;
        }
        else {
            cout << n1 + n2 - m*(m+1) << endl;
        }
    }

}
