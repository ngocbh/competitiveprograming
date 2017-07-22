#include <bits/stdc++.h>

using namespace std;
int n,a,b;
int main()
{   freopen("KTX.inp","r",stdin);
    scanf("%d", &n, &a, &b);
    if ( a*b > n*6 ) { cout<<a*b<<'\n'<<a<<" "<<b; return 0; }

    for ( int i = a; i <= n; i++ ) {
        if ( n*6 % a == 0 && n*6 / a >= b  ) {
            cout<<n*6<<" "
        }
    }

}
