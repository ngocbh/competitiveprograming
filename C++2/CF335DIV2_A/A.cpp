#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, x, y, z;

int main()
{
    //freopen("A.inp","r",stdin);
    cin >> a >> b >> c;
    cin >> x >> y >> z;

    int thieu = 0, thua = 0;
    if ( a < x ) thieu += x - a;
    if ( b < y ) thieu += y - b;
    if ( c < z ) thieu += z - c;
    if ( a > x ) thua += (a - x)/2;
    if ( b > y ) thua += (b - y)/2;
    if ( c > z ) thua += (c - z)/2;
    cout << ( thua >= thieu ? "Yes" : "No" );
}
