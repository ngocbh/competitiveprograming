#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
int n, t, k;
double f[N][N];

double calc(int h,int m)
{
    double d1 = (double) h * 30 + (double) m / 2;
    double d2 = (double) m * 6;
    return (double) (min(abs(d1-d2),360-abs(d1-d2)));
}

void out(int i,int j)
{
    if ( i < 10 ) cout << 0 << i << ":";
    else cout << i << ":";
    if ( j < 10 ) cout << 0 << j << endl;
    else cout << j << endl;
}

int main()
{   //freopen("TIMEASR.inp","r",stdin);
    ios::sync_with_stdio(0);

    cin >> t;

    for (int i = 0; i <= 11; i++)
        for (int j = 0; j <= 59; j++)
                f[i][j] = calc(i,j);

    while ( t-- ) {
        double k;
        cin >> k;
        bool ok = true;
        for (int i = 0; i <= 11; i++)
            for (int j = 0; j <= 59; j++) {
                if ( abs(f[i][j] - k) <= (double) 1/120 )
                    out(i,j), ok = false;
            }
    }

}
