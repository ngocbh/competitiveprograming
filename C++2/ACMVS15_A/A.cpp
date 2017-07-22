#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;

int n, m;
int a[N];

bool check(int x)
{
    int res = 0;
    for (int i = 1; i <= m; i++)
        res += ceil((double)a[i]/x);
    if ( res <= n )
        return true;
    else return false;
}

int main()
{   //freopen("A.inp","r",stdin);
    cin >> n >> m;
    int _max = 0;
    for (int i = 1; i <= m; i++)
        cin >> a[i], _max = max(_max,a[i]);

    int l = 1, r = _max, m, ans = 1;

    while ( l <= r ) {
        int m = ( l + r ) / 2;
        if ( !check(m) ) {
            l = m+1;
            ans = m;
        }
        else r = m-1;
    }

    cout << ans + 1;
}
