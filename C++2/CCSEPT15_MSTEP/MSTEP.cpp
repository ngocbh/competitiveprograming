#include <bits/stdc++.h>

const long N = 500 + 10;
using namespace std;
struct data{
    int x,y;
};
int n;
int a[N][N];
data f[N*N];
int main()
{   //freopen("MSTEP.inp","r",stdin);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while ( t-- ) {
            cin >> n;
            for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= n; j++) {
                               cin >> a[i][j];
                               f[a[i][j]].x = i;
                               f[a[i][j]].y = j;
                    }
            int res = 0;
            for (int i = 2; i <= n*n; i++) {
                    res += abs(f[i].x - f[i-1].x) + abs(f[i].y - f[i-1].y);
            }
            cout << res << endl;

    }

}
