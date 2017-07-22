/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 10000000 + 100;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, t, MAX;
bool ca[N];
int p[N], pp[N], in[N];
int r[N], q[N];

void init()
{
    for (int i = 1; i <= MAX; i++) p[i] = i;
    memset(ca,true,sizeof ca);
    int x;
    for (int i = 2; i <= MAX; i++) {
        if ( !ca[i] ) continue;
        p[i] = i-1;
        for (int j = 2; i*j <= MAX; j++) {
            x = i*j;
            ca[x] = false;
            pp[x] = i;
            p[x] /= i;
            p[x] *= (i-1);
        }
    }
}

void solve(int n)
{
    LL ans = 0;
    int x = (int)sqrt(n);
    for (int i = 1; i <= x; i++) {
        if ( i == x && i*i == n ) {
            ans += 1LL*p[i]*i;
            break;
        }
        if ( n % i == 0 ) {
            ans += 1LL*p[i]*i;
            ans += 1LL*p[n/i]*(n/i);
        }
    }
    printf("%lld\n",ans);
}

void solve_1()
{
    q[1] = 0;
    r[1] = 1;
    LL x , cp, res;

    for (int i = 2; i <= MAX; i++) {
        if ( ca[i] ) {
                res = 1LL*p[i]*i + 1;
                q[i] = res/MOD;
                r[i] = res%MOD;
                continue;
        }
        cp = 1; x = i;
        res = 1;
        while ( x % pp[i] == 0 ) {
            cp = cp*pp[i];
            res += cp*cp*(pp[i]-1)/pp[i];
            x /= pp[i];
        }
        res *= q[x]*MOD + r[x];
        q[i] = res/MOD;
        r[i] = res%MOD;
    }

    for (int i = 1; i <= t; i++) printf("%lld\n", 1LL*q[in[i]]*MOD + r[in[i]]);
}

int main()
{
    //freopen("SMPLSUM.inp","r",stdin);
    //freopen("SMPLSUM.out","w",stdout);

    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &in[i]);
        MAX = max(MAX,in[i]);
    }

    init();

    //if ( MAX <= 10000 )
        solve_1();
    //else {
        //for (int i = 1; i <= t; i++) solve(in[i]);
    //}

}
