/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100 + 10;
const long long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

LL m, n, hp, sp, ans, D, np;
LL h[N*N], ca[N][N], _pow[N*N];
char a[N][N], s[N*N];

LL get(int i,int j)
{
    return (h[j] - (h[i-1]*_pow[j-i+1] % MOD) + MOD*MOD) % MOD;
}

void dfs(int u,int v,int c,bool ok)
{
    bool x = false;
    h[c] = (h[c-1]*29 + a[u][v] - 'A' + 1) % MOD;
    if ( c >= np && get(c-np+1,c) == hp )
            x = true;

    if ( u == n && v == m ) {
        if ( ok | x )
            ans = (ans + 1) % MOD;
        return;
    }
    if ( v + 1 <= m ) {
        dfs(u,v+1,c+1,ok | x);
    }
    if ( u + 1 <= n ) {
        dfs(u+1,v,c+1,ok | x);
    }
}

int main()
{
    freopen("WORDGAME.inp","r",stdin);
    //freopen("WORDGAME.out","w",stdout);

    cin >> n >> m >> D;

    scanf("%s", s+1);
    np = strlen(s+1);
    for (int i = 1; i <= np; i++)
        hp = ( 1LL*hp*29 + s[i] - 'A' + 1) % MOD;

    for (int i = 1; i <= n; i++) {
        string ss;
        cin >> ss;
        for (int j = 0; j < ss.size(); j++)
            a[i][j+1] = ss[j];
    }

    _pow[0] = 1; h[0] = 0;
    for (int i = 1; i <= n; i++)
        _pow[i] = (_pow[i-1]*29) % MOD;

    dfs(1,1,1,false);
    cout << ans ;
}
