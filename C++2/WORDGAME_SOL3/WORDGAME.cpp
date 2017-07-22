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
int h[N*N], ca[N][N], _pow[N*N], next[N][2*N];
LL d[N][N][N*2];
char a[N][N];
string s;

vector <int> b[N][N];

LL dfs(int u,int v,int c)
{
    LL x = 0,y = 0;

    if ( d[u][v][c] != -1 ) return d[u][v][c];

    if ( u == n && v == m ) {
        if ( c == np )
            d[u][v][c] = 1;
        else
            d[u][v][c]= 0;

        return d[u][v][c];
    }

    if ( u + 1 <= n ) {
            x = (x + dfs(u+1,v,next[c][a[u+1][v]])) % D;
    }

    if ( v + 1 <= m ) {
            x = (x + dfs(u,v+1,next[c][a[u][v+1]])) % D;
    }

    d[u][v][c] = x;
    return x;
}

int main()
{
    freopen("WORDGAME.inp","r",stdin);
    //freopen("WORDGAME.out","w",stdout);

    cin >> n >> m >> D;
    cin >> s;
    np = s.size();
    s = "0" + s;
    for (int i = 1; i <= n; i++) {
        string ss;
        cin >> ss;
        for (int j = 0; j < ss.size(); j++)
            a[i][j+1] = ss[j];
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= np; k++)
                d[i][j][k] = -1;

    for (int i = 0; i < np; i++) {
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            string s1 = s.substr(1,i+1);
            s1 = s1 + ch;
            while ( !s1.empty() && s.substr(1,s1.size()) != s1 ) s1.erase(s1.end()-1,s1.end());
            next[i][ch] = s1.size();
        }
    }

    ans = dfs(1,1,next[0][a[1][1]]);

    cout << ans;
}
