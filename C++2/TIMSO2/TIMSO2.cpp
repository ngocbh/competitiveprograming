#include <bits/stdc++.h>

const long N = 10000;
using namespace std;

int m;
int a[N], sz = 0;
int main()
{   //freopen("TIMSO2.inp","r",stdin);
    cin >> m;
    if ( m == 1 ) {
        cout << m;
        return 0;
    }
    if ( m == 0 ) {
        cout << 10;
        return 0;
    }
    while ( m > 1 ) {
        int ok = true;
        for (int i = 9; i >= 2; i--) {
            if ( m % i == 0 ) {  a[++sz] = i, m /= i, ok = false; break; }
        }
        if ( ok ) break;
    }

    if ( m > 1 ) cout << -1;
    else
    {
        sort(a+1,a+sz+1);
        for (int i = 1; i <= sz; i++) cout << a[i];
    }

}
