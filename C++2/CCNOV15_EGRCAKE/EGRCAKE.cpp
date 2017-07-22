/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 10000;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int t, m, n;
int a[N];

void solve(int n,int m)
{
    if ( __gcd(n,m) == 1 ) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No " << n/__gcd(n,m) << endl;
}

int main()
{
    //freopen("EGRCAKE.inp","r",stdin);
    //freopen("EGRCAKE.out","w",stdout);

    cin >> t;
    while ( t-- ) {
        cin >> n >> m;
        solve(n,m);
    }

}
