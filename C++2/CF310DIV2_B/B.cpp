#include <bits/stdc++.h>
const long N = 1000 + 10;
using namespace std;
int n,a[N];
int ca(int x)
{
    if ( x < 0 ) return n-1;
    if ( x > n-1 ) return 0;
    return x;
}
int main()
{  // freopen("B.inp","r",stdin);
    cin>>n;
    for (int i = 1; i <= n; i++) cin>>a[i];
    for (int i = 1; i <= n+1; i++) {
        for (int i = 1; i <= n; i++)
            if ( i % 2 == 1 ) a[i] = ca(a[i]+1);
            else a[i] = ca( a[i] - 1 );
        int cc=0;
        for (int i = 1; i <= n; i++)
            if ( a[i] == i-1 ) ++cc;
        if ( cc == n ) { cout<<"YES"; return 0; }
    }
    cout<<"NO";

}
