#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
int n, a[N];
int _max;

int gcd(int x,int y)
{
    int r;
    while ( y != 0 ) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

bool check(int x,int y)
{
        LL t, tx, ty;
        t = gcd(x,y);
        t = (1LL*x*y) / t;
        tx = t / x;
        ty = t / y;
        while ( tx % 2 == 0 && tx != 0 ) tx /= 2;
        while ( tx % 3 == 0 && tx != 0 ) tx /= 3;
        while ( ty % 2 == 0 && ty != 0 ) ty /= 2;
        while ( ty % 3 == 0 && ty != 0 ) ty /= 3;

        if ( ( tx == 0 || tx == 1 )&& ( ty == 0 || ty == 1 ) ) return true;
        return false;
}

int main()
{   //freopen("B.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
            _max = max(_max , a[i]);
    }

    for (int i = 1; i <= n; i++) {
        if ( !check(a[i],_max) ) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;

}
