#include <bits/stdc++.h>

using namespace std;

const long N = 5000 + 10;

int n, m, k, x;
bool p[N][N], a[N][N][3];
int res[5], sl[5], slc[5];
int h[30010], c[30010];

void solve_H()
{
    for (int i = 0; i <= m; i++) a[x][i][1] = 1;
}

void solve_V()
{
    for (int i = 0; i <= n; i++) a[i][x][2] = 1;
}

void solve_1()
{
    for (int i = 1; i <= k; i++) {
        char c;
        cin >> c >> x;
        if ( c == 'V' ) solve_V();
        else solve_H();
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            x = a[i][j-1][2] + a[i][j][2] + a[i-1][j][1] + a[i][j][1];
            ++res[x];
        }
    for (int i = 0; i <= 4; i++) cout << res[i] << " ";
}

void solve_2()
{
    for (int i = 1; i <= k; i++) {
        char cc;
        cin >> cc >> x;
        if ( cc == 'V' ) c[x] = 1;
        else h[x] = 1;
    }

    sl[0] = m*n;

    if (h[0]) sl[0] -= m, sl[1] += m;

    for (int i = 1; i <= n-1; i++)
    {
        if ( !h[i] ) continue;
        if ( !h[i-1] ) {
            sl[0] -= 2*m; sl[1] += 2*m;
        }
        else {
            sl[0] -= m; sl[2] += m;
        }
    }

    if ( h[n] ) {
        if ( !h[n-1] ) sl[0] -= m, sl[1] += m;
        else sl[1] -= m, sl[2] += m;
    }

    for (int i = 0; i <= 4; i++) slc[i] = sl[i];

    if ( c[0] ) {
            slc[0] -= sl[0]/m, slc[1] += sl[0]/m;
            slc[1] -= sl[1]/m; slc[2] += sl[1]/m;
            slc[2] -= sl[2]/m; slc[3] += sl[2]/m;
    }



    for (int i = 1; i < m; i++)
    {
        if ( !c[i] ) continue;
        if ( !c[i-1] ) {
            slc[0] -= 2*sl[0]/m, slc[1] += 2*sl[0]/m;
            slc[1] -= 2*sl[1]/m; slc[2] += 2*sl[1]/m;
            slc[2] -= 2*sl[2]/m; slc[3] += 2*sl[2]/m;
        }
        else {
            slc[0] -= sl[0]/m; slc[2] += sl[0]/m;
            slc[1] -= sl[1]/m; slc[3] += sl[1]/m;
            slc[2] -= sl[2]/m; slc[4] += sl[2]/m;
        }
    }

    if ( c[m] ) {
        if ( !c[m-1] ) {
            slc[0] -= sl[0]/m, slc[1] += sl[0]/m;
            slc[1] -= sl[1]/m; slc[2] += sl[1]/m;
            slc[2] -= sl[2]/m; slc[3] += sl[2]/m;
        }
        else {
            slc[1] -= sl[0]/m; slc[2] += sl[0]/m;
            slc[2] -= sl[1]/m; slc[3] += sl[1]/m;
            slc[3] -= sl[2]/m; slc[4] += sl[2]/m;
        }
    }

    for (int i = 0; i <= 4; i++) cout << slc[i] << " ";
}

int main()
{
    freopen("ROADS.inp","r",stdin);
    freopen("ROADS.out","w",stdout);

    cin >> n >> m >> k;
    //if ( n <= 5000 && m <= 5000 ) solve_1();
   // else
        solve_2();
}
