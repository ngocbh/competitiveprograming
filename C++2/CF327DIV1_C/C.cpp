#include <bits/stdc++.h>

const long N = 1000 + 10;
const long oo = 1000000000 + 7;
using namespace std;
typedef pair <int,int> ii;

int n, m;

int d[N][N], f[4][4];

char a[N][N];
string s;

int solve(int x,int y)
{
    queue <ii> qu;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if ( a[i][j]-'0' == x ) {
                qu.push(ii(i,j));
                d[i][j] = 0;
            }
            else d[i][j] = oo;
        }

    while ( !qu.empty() ) {
        int u, v;
        u = qu.front().first;
        v = qu.front().second;
        qu.pop();

        for (int i = -1; i <= 1; i++)
            for (int  j = -1; j <= 1; j++) {
                    if ( j == 0 && i == 0 ) continue;
                    if ( j != 0 && i != 0 ) continue;
                    if ( a[u+i][v+j] == '#' ) continue;
                    if ( a[u+i][v+j]-'0' == y )
                        return d[u][v] + 1;

                    if ( a[u+i][v+j] == '.' && d[u+i][v+j] > d[u][v] + 1) {
                        d[u+i][v+j] = d[u][v] + 1;
                        qu.push(ii(u+i,v+j));
                    }
            }
    }
    return oo;
}

int main()
{   freopen("C.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    getline(cin,s);
    for (int i = 1; i <= n; i++)
    {
        getline(cin,s);
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
        }
    }

    for (int i = 1; i <= n; i++) a[i][0] = a[i][m+1] = '#';
    for (int i = 1; i <= m; i++) a[0][i] = a[n+1][i] = '#';

    for (int i = 1; i <= 2; i++)
        for (int j = i + 1; j <= 3; j++)
            {
                f[i][j] = solve(i,j) - 1;
            }

    int ans = oo;
    ans = min(ans,f[1][2] + f[1][3]);
    ans = min(ans,f[1][2] + f[2][3]);
    ans = min(ans,f[1][3] + f[2][3]);
    if ( ans < oo )
    cout << ans;
    else cout << -1;

}
