/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 0;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n;

int main()
{
    freopen("CURRENCY.inp","r",stdin);
    freopen("CURRENCY.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if ( a == 1 ) {
            cout << -1;
            return 0;
        }
    }

    cout << 1;
}
