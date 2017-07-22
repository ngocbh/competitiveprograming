#include <bits/stdc++.h>

using namespace std;

const long N = 500 + 10;

int n, m, x, y;
int ca[N][N], cs[100010];
string s;

int main()
{
    //freopen("C.inp","r",stdin);
    ios::sync_with_stdio(0);

    cin >> n >> m >> x >> y ;
    cin >> s;


    int rem = 1;
    memset(ca,0,sizeof ca);

    ca[x][y] = 1;

    for (int i = 0; i < s.size(); i++) {
        int u = x, v = y;
        if ( s[i] == 'U' ) {
            if ( x > 1 ) --x, cs[i] = 1;
            else cs[i] = 0;
            if ( ca[x][y] ) cs[i] = 0;
            if ( i == s.size() - 1 ) {
                if ( ca[x][y] ) rem = 0;
            }
            ca[x][y] = 1;
        }
        if ( s[i] == 'D' ) {
            if ( x < n ) ++x, cs[i] = 1;
            else cs[i] = 0;
            if ( ca[x][y] ) cs[i] = 0;
            if ( i == s.size() - 1 ) {
                if ( ca[x][y] ) rem = 0;
            }
            ca[x][y] = 1;
        }
        if ( s[i] == 'L' ) {
            if ( y > 1 ) --y, cs[i] = 1;
            else cs[i] = 0;
            if ( ca[x][y] ) cs[i] = 0;
            if ( i == s.size() - 1 ) {
                if ( ca[x][y] )
                    rem = 0;
            }
            ca[x][y] = 1 ;
        }
        if ( s[i] == 'R' ) {
            if ( y < m ) ++y, cs[i] = 1;
            else cs[i] = 0;
            if ( ca[x][y] ) cs[i] = 0;
            if ( i == s.size() - 1 ) {
                if ( ca[x][y] ) rem = 0;
            }
            ca[x][y] = 1;
        }
        if ( i == s.size() - 1 ) {
            if ( u == x && v == y ) rem = 0;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ( ca[i][j] ) ++ans;

    cout << 1 << " ";
    for (int i = 0; i < s.size()-1; i++) cout << cs[i] << " ";

    cout << n*m - ans + rem;
}
