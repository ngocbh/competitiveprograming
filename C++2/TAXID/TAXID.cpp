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

LL n, m, p , q, slpt1 = 1, num, slpt2 = 1, slpt, ans = 0, MAX = 0;
int c[N], x[N];

void printf_ans()
{
    int res = 0;
    for (int i = 1; i <= num; i++) {
        res = res*36 + x[i];
        if ( res == 0 ) continue;
        if ( x[i] < 10 ) cout << x[i];
        else cout << (char) (x[i] - 10 + 'a');
    }
    exit(0);
}

void ktkq()
{
    if ( x[0] == 0 ) return;
    if ( MAX <= c[(p-1)/2]-1 || x[0] > n ) return;
    ++ans;
    if ( ans == q ) printf_ans();
}


void duyet(int i)
{
    if ( i > num ) {

        ktkq();
        return;
    }
    for (int j = 0; j <= c[(p+1)/2]-1; j++) {
        int mm = 0, mres = 0;
        mm = MAX;
        mres = x[0];
        x[0] = x[0]*36 + j;
        MAX = max(MAX,1LL*j);
        x[i] = j;
        if ( x[0] <= n )
            duyet(i+1);
        x[0] = mres;
        MAX = mm;
    }
}

void solve()
{
    LL qq = q;
    q = oo*10000;
    duyet(1);
    slpt = ans;
    ans = 0;
    memset(x,0,sizeof x);
    q = slpt+1-qq;
    duyet(1);
}

int main()
{
    freopen("TAXID.inp","r",stdin);
    //freopen("TAXID.out","w",stdout);
    cin >> n >> m >> p >> q;

    for (int i = 1; i <= (m-1)/2; i++)
        cin >> c[i];

    c[(m+1)/2] = 36;
    num = (int) (log(n) / log(36)) + 1;

    if ( p % 2 == 0 ) {
        solve();
        return 0;
    }

    duyet(1);
}
