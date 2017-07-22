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
int r[N], q[N], c[N], cf[N], pos[N];
int cc[670000][20], cs[670000][20];

void init()
{
    for (int i = 1; i <= MAX; i++) p[i] = i;
    memset(ca,true,sizeof ca);
    int x;
    for (int i = 2; i <= MAX; i++) {
        if ( !ca[i] ) continue;
        p[i] = i-1;
        pp[i] = i;
        for (int j = 2; i*j <= MAX; j++) {
            x = i*j;
            ca[x] = false;
            if ( !pp[x] ) pp[x] = i;
            p[x] /= i;
            p[x] *= (i-1);
        }
        x = 1;
    }
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
        cp = 1;
        x = i/cs[pos[pp[i]]][cf[i]];
        res = cc[pos[pp[i]]][cf[i]];
        res = res*(1LL*q[x]*MOD + r[x]);
        q[i] = res/MOD;
        r[i] = res%MOD;
    }

    for (int i = 1; i <= t; i++) printf("%lld\n", 1LL*q[in[i]]*MOD + r[in[i]]);
}

int main()
{
    freopen("SMPLSUM.inp","r",stdin);
    //freopen("SMPLSUM.out","w",stdout);

    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &in[i]);
        MAX = max(MAX,in[i]);
    }

    init();

    for (int i = 2; i <= MAX; i++) {
        if ( ca[i] ) {
            cf[i] = 1;
            continue;
        }
        if ( pp[i/pp[i]] != pp[i] ) {
            cf[i] = 1;
            continue;
        }
        cf[i] = cf[i/pp[i]] + 1;
    }


    int y = 1, m = 0, x;
    for (int i = 2; i <= MAX; i++) {
        x = pp[i]; y = x;
        if ( pos[x] ) continue;
        pos[x] = ++m;
        cc[m][0] = 1;
        cs[m][0] = 1;
        for (int j = 1; j <= 20; j++) {
            if ( y > N ) break;
            cs[m][j] = y;
            cc[m][j] = cc[m][j-1] + y*y*(x-1)/x;
            y = y*x;

        }
    }
    for (int i = 1; i <= t; i++) printf("%lld\n", 1LL*q[in[i]]*MOD + r[in[i]]);
    return 0;
    solve_1();

}
