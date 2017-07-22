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

LL m, n, hp, sp, ans, np;
int D;
LL ca[N][N], d[N][N], cb[N][N], cd[N][N];
char a[N][N], s[N*N];

LL calc(int u,int v,int x,int y)
{
    for (int i = x; i <= n; i++){
        for (int j = y; j <= m; j++)
        {
            if ( !cb[i][j] ) break;
            cb[i][j] = false;
        }
    }

    return d[u][v]*d[n-x+1][m-y+1];
}

void solve(int u,int v)
{
    ca[u][v] = 1;
    cd[u][v] = 1;
    for (int i = 0; i <= np; i++) {
        if ( u + i > n ) break;
        for (int j = 0; j <= np; j++) {
            if ( v + j > m ) break;
            if ( i == 0 && j == 0 ) {
                if ( ca[u+i][v+j] == np )
                ans = (ans + calc(u,v,u+i,v+j)) % D;
                continue;
            }
            ca[u+i][v+j] = cd[u+i][v+j] = 0;
            if ( i == 0 ) if ( ca[u+i][v+j-1] == j+1 && a[u+i][v+j] == s[j+2] ) {
                    ca[u+i][v+j] = j,cd[u+i][v+j] += cd[u+i][v+j-1];
                    continue;
            }
            if ( j == 0 ) if ( ca[u+i-1][v+j] == i+1 && a[u+i][v+j] == s[i+2] ) {
                    ca[u+i][v+j] = i,cd[u+i][v+j] += cd[u+i-1][v+j];
                    continue;
            }
            if ( a[u+i][v+j] != s[i+j+1] ) continue;
            if ( ca[u+i-1][v+j] == i+j ) cd[u+i][v+j] += cd[u+i-1][v+j];
            if ( ca[u+i][v+j-1] == i+j ) cd[u+i][v+j] += cd[u+i][v+j-1];
            if ( ca[u+i-1][v+j] == i+j || ca[u+i][v+j-1] == i+j ) ca[u+i][v+j] = i+j+1;
            if ( ca[u+i][v+j] == np )
                ans = (ans + cd[u+i][v+j]*calc(u,v,u+i,v+j)) % D;
        }
    }
    ca[u][v] = 0;
    cd[u][v] = 0;

}

int main()
{
    freopen("WORDGAME.inp","r",stdin);
    freopen("WORDGAME.out","w",stdout);

    cin >> n >> m >> D;

    scanf("%s", s+1);
    np = strlen(s+1);

    for (int i = 1; i <= n; i++) {
        string ss;
        cin >> ss;
        for (int j = 0; j < ss.size(); j++)
            a[i][j+1] = ss[j];
    }

    for (int i = 1; i <= n; i++) d[i][1] = 1;
    for (int i = 1; i <= m; i++) d[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            d[i][j] = ( d[i-1][j] + d[i][j-1] ) % D;

    memset(cb,true,sizeof cb);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ( a[i][j] == s[1] && cb[i][j] )
                solve(i,j);

    cout << ans ;
}
