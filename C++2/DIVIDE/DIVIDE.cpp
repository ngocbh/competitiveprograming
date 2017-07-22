/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000 + 10;
const long long oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

LL t, n;
LL a[N], c[N][N], ans ;
int x[N];

LL _pow(LL a,LL k,LL p)
{
    LL t = a, tg = k, r = 1;
    while ( tg > 0 ) {
        if ( tg % 2 == 1 ) r = (r*t) % MOD;
        t = (t*t) % MOD;
        tg /= 2;
    }

    return r;
}

LL calc(LL a,LL b)
{
    return min(_pow(a,b,MOD),_pow(b,a,MOD));
}

void ktkq()
{
    int t0 = 0, t1 = 0;
    for (int i = 1; i <= n; i++)
        if ( x[i] == 0 ) ++t0;
        else ++t1;

    if ( t1 <= 0 || t0 <= 0 ) return;

    LL res0 = 0, res1 = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            if ( x[i] == 0 && x[j] == 0 )
                res0 = max(res0,c[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            if ( x[i] == 1 && x[j] == 1 )
                res1 = max(res1,c[i][j]);


    ans = min(ans,max(res0,res1));

}

void duyet(int i)
{
    if ( i > n ) {
        ktkq();
        return;
    }

    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        duyet(i+1);
    }
}

int main()
{   //freopen("DIVIDE.inp","r",stdin);
    //freopen("DIVIDE.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> t;
    while ( t-- ) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        ans = oo*oo;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                c[i][j] = calc(a[i],a[j]);

        duyet(1);
        cout << ans << endl;
    }
}
