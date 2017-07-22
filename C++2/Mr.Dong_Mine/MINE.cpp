#include <bits/stdc++.h>

const long N = 20 + 10;
using namespace std;
typedef pair <int,int> ii;

int n, m, sl;
int a[N][N], x[N][N], MIN[N][N], MAX[N][N];

void init()
{
    memset(MIN,0,sizeof MIN);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            for (int ci = -2; ci <= 2; ci++)
                for (int cj = -2; cj <= 2; cj++) {
                        int u = i+ci, v = j+cj;
                        if ( abs( i - u ) + abs( j - v ) <= 2 && u >= 1 && v >= 1 && u <= n && v <= m ) ++MAX[i][j];
                }
        }
}

void print_ans()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }
    exit(0);
}

void duyet(int i,int j)
{
    bool ok = true;
    if ( i > n ) {
        print_ans();
    }

    x[i][j] = 0;
    for (int ci = -2; ci <= 2; ci++)
                for (int cj = -2; cj <= 2; cj++) {
                        int u = i+ci, v = j+cj;
                        if ( abs( i - u ) + abs( j - v ) <= 2 && u >= 1 && v >= 1 && u <= n && v <= m ) --MAX[u][v];
                        if ( MAX[u][v] < a[u][v] ) ok = false;
                }

    if ( ok ) {
        if ( j < m ) duyet(i,j+1);
        else duyet(i+1,1);
    }

    for (int ci = -2; ci <= 2; ci++)
                for (int cj = -2; cj <= 2; cj++) {
                        int u = i+ci, v = j+cj;
                        if ( abs( i - u ) + abs( j - v ) <= 2 && u >= 1 && v >= 1 && u <= n && v <= m ) ++MAX[u][v];
                }

    x[i][j] = 1;
    ok = true;
    for (int ci = -2; ci <= 2; ci++)
                for (int cj = -2; cj <= 2; cj++) {
                        int u = i+ci, v = j+cj;
                        if ( abs( i - u ) + abs( j - v ) <= 2 && u >= 1 && v >= 1 && u <= n && v <= m ) ++MIN[u][v];
                        if ( MIN[u][v] > a[u][v] ) ok = false;
                }

    if ( ok ) {
        if ( j < m ) duyet(i,j+1);
        else duyet(i+1,1);
    }

    for (int ci = -2; ci <= 2; ci++)
                for (int cj = -2; cj <= 2; cj++) {
                        int u = i+ci, v = j+cj;
                        if ( abs( i - u ) + abs( j - v ) <= 2 && u >= 1 && v >= 1 && u <= n && v <= m ) --MIN[u][v];
                }

}
int main()
{   freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    init();
    duyet(1,1);
}
