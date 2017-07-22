#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n;
int a[N];
int k = 1, ib = 1, ie;

void calc_ib()
{
    ib = 0;
    for (int i = k; i<= n; i++) {
        if ( a[i] <= a[i-1] && a[i] < a[i+1] ) {
            k = i;
            ib = k;
            return;
        }
    }
}

void calc_ie()
{
    for (int i = k+1; i <= n; i++) {
        if ( a[i] >= a[i+1] && a[i] > a[i-1] ) {
            k = i;
            ie = k;
            return;
        }
    }
}

int main()
{
    freopen("CLIMB.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[1] + 1; a[n+1] = a[n] - 1;


    while ( ib > 0 ) {
        calc_ib();
        if ( ib > 0 ) {
            calc_ie();
            ans = max(ans, a[ie] - a[ib]);
        }
    }
}
