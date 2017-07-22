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

int n, k;
LL a[N], b[N], _pow10[N], _pow9[N];

void init()
{
    _pow10[0] = 1;
    for (int i = 1; i <= k+1; i++) _pow10[i] = _pow10[i-1]*10;
    _pow9[0] = 9;
    for (int i = 1; i <= k+1; i++) _pow9[i] = _pow9[i-1]*10 + 9;

}

LL calc(LL A,LL B,LL C)
{
    if ( A > B ) return 0;
    return ( B/C - (A+C-1)/C + 1 );

}

int main()
{
    freopen("B.inp","r",stdin);
    //freopen(".out","w",stdout);

    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n/k; i++) cin >> a[i];
    for (int i = 1; i <= n/k; i++) cin >> b[i];
    init();

    LL ans = 1;
    for (int i = 1; i <= n/k; i++) {
        LL res = 0;
        res = calc(0,b[i]*_pow10[k-1] - 1,a[i]);
        res += calc((b[i]+1)*_pow10[k-1],_pow9[k-1],a[i]);
        ans = (ans*res) % MOD;
    }

    cout << ans;

}
