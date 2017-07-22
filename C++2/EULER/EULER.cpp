#include <bits/stdc++.h>

const long N = 10000000 + 10;

using namespace std;
typedef long long LL;

int n;
LL ca[N];

LL calc(int n)
{
    if ( n <= 1 ) return n;
    if ( n < N && ca[n] != -1 ) return ca[n];

    LL s ;
    LL &ans = ( n < N ) ? ca[n] : s;
    ans = (1LL*n*(n+1) / 2);

    int d = 1;
    for (d = 2; d*d <= n; d++)
        ans -= calc(n/d);

    for (d = n/d; d > 0; d--)
        ans -= calc(d) * (n/d - n/(d+1));

    return ans;
}

int main()
{
    //freopen("EULER.inp","r",stdin);
    cin >> n;
    memset(ca,-1,sizeof ca);
    cout << calc(n);
}
