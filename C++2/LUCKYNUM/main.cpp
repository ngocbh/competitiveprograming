/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 20;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

LL a[N], x[N];

void ktkq(int n)
{
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res = res*10 + x[i];
    }
    LL rr = res, cr = 0;
    while ( rr % 2 == 0 ) {
        ++cr;
        rr /= 2;
    }
    a[cr] = min(a[cr],1LL*res);
}

void duyet(int i,int n)
{
    if ( i > n ) {
        ktkq(n);
        return;
    }
    for (int j = 0; j <= 1; j++) {
        x[i] = 4 + 3*j;
        duyet(i+1,n);
    }
}

int main()
{
    //freopen("LUCKYNUM.inp","r",stdin);
    //freopen(".out","w",stdout);
    int t = 0;

    for (int i = 1; i <= 20; i++) a[i] = 7*oo;

    for (int i = 1; i <= 18; i++) duyet(1,i);

    for (int i = 4; i <= 16; i+=2) a[i] = min(a[i],a[i-2]*4);
    for (int i = 5; i <= 16; i+=2) a[i] = min(a[i],a[i-2]*4);
    a[0] = 1;
    for (int i = 18; i >= 1; i--) a[i] = min(a[i],a[i+1]);

    cin >> t;
    while ( t-- ) {
        LL n;
        cin >> n;
        LL ans = 0, nn = n;
        while ( nn % 5 == 0 ) nn /= 5, ++ans;
        while ( nn % 2 == 0 ) nn /= 2, --ans;
        if ( ans < 0 ) ans = 0;
        cout << n*a[ans] << endl;
    }

}
