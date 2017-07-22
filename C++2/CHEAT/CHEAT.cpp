#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;

long long n, x, y;
int res, b[N];

int main()
{
    freopen("CHEAT.inp","r",stdin);

    cin >> n;

    y = n;
    int len = 0;
    while ( y > 0 ) { b[++len] = y % 10; y /= 10; }

    int ans = N;
    res = 0;
        x = 0;

        for (int i = 1; i <= len+2; i++) {
            if ( x % 10 != b[i] ) ++res;
            x /= 10;
        }

    ans = res;

    for (long long i = 1; i*i <= 10*n; i++)  {
        res = 0;
        x = i*i;

        for (int j = 1; j <= len+2; j++) {
            if ( x % 10 != b[j] ) ++res;
            x /= 10;
        }

        if ( ans > res ) ans = res;
    }
    cout << ans;
}
