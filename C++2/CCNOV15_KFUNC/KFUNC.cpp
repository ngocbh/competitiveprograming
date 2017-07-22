/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int t;
LL a,d,ca[10], f[10];
LL l, r;

int main()
{
    //freopen("KFUNC.inp","r",stdin);
    //freopen("KFUNC.out","w",stdout);

    cin >> t;

    while ( t-- ) {
        cin >> a >> d >> l >> r;
        int x;
        x = ((a%9) + ((l-1)%9)*(d%9))   % 9;

        if ( x == 0 ) x = 9;
        int ck = 0,i = 1;
        LL ll = l-1;
        memset(ca,true,sizeof ca);
        memset(f,0,sizeof f);

        while ( ca[x] ) {
            f[x] = 1;
            ca[x] = 0;
            ++ck;
            ++ll;
            x = ((a%9) + ((ll%9)*(d%9) )) % 9;
            if ( x == 0 ) x = 9;
        }

        for (int i = 1; i <= 9; i++) f[i] = f[i]*(r-l+1)/ck;
        for (int i = 1; i <= (r-l+1)%ck; i++) {
            f[x]++;
            ++ll;
            x = ((a%9) + ((ll%9)*(d%9) )) % 9;
            if ( x == 0 ) x = 9;
        }

        LL ans = 0;
        for (int i = 1; i <= 9; i++) ans += f[i]*i;

        cout << ans << endl;
    }

}
