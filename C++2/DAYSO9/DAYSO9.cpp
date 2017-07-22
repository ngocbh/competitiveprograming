/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

LL n;
int ck = 0;
LL s[N], res[N];

LL solve(LL n)
{
    LL res = 0;
    while ( n > 0 ) {
        res = res*10 + n%10;
        n/=10;
    }
    res += 2;
    return res;
}

int main()
{
    //freopen("DAYSO9.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> n;
    if ( n == 1 ) {
        cout << 1;
        return 0;
    }

    --n;

    LL a = 1;
    for (int i = 1 ; i < 100; i++) {
            s[a] = 1,a = solve(a);
            ++ck;
            res[ck] = a;
            if ( s[a] ) {
                    break;
            }
    }

    --ck;
    if (n%ck == 0 ) {
            cout << res[ck];
            return 0;
    }
    cout << res[n%ck];
}
