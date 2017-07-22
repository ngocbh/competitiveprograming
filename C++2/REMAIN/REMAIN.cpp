/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>
#define cin fi
#define cout fo
const long N = 1000000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
ifstream fi("REMAIN.inp");
ofstream fo("REMAIN.out");

typedef long long LL;
typedef pair <int,int> ii;

int n;
LL a[N];

LL gcd(LL a,LL b)
{
    LL m = a, n = b, r;
    while ( n != 0 ) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int main()
{
    //freopen("REMAIN.inp","r",stdin);
    //freopen("REMAIN.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    LL d = abs(a[1] - a[2]);

    for (int i = 3; i <= n; i++)
        d = gcd(d,abs(a[i] - a[i-1]));

    cout << d;
}
