/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 10000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, k;
int a[N], x[N], f[N], num;

void calc(int l,int r)
{
    if ( l > r ) return;

    if ( l == r ) {
        f[a[l]] = ++num;
        return;
    }

    int _max = 0, cs = 0;
    for (int i = l; i <= r; i++) {
        if ( a[i] > _max ) _max = a[i], cs = i;
    }

    calc(l,cs-1);
    calc(cs+1,r);
    f[a[cs]] = ++num;
}

bool check(int l,int r)
{
    memset(f,0,sizeof f);
    num  = 0;
    calc(1,n);

    for (int i = 1; i <= n; i++) {
        if ( f[i] != i ) return false;
    }
    return true;
}

int main()
{
    //freopen("VOITSORT.inp","r",stdin);
    //freopen("VOITSORT.out","w",stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (check(1,n)) ++ans;
        next_permutation(a+1,a+n+1);
    }

    cout << ans;
}
