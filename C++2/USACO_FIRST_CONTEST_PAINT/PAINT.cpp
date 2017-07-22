#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);

    cin >> a >> b >> c >> d;

    if ( a > c ) swap(a,c), swap(b,d);

    if ( c > b ) cout << b-a+d-c << endl;
    else cout << max(d,b) - a << endl;
}
