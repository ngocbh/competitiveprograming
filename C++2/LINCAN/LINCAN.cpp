#include <bits/stdc++.h>

const long N = 100 ;
using namespace std;
typedef long long LL;
LL q, a ,b;

void solve(LL a, LL b)
{

    LL r,aa = a,bb = b;
    if ( a % 2 == 1 ) aa = a+1;
    if ( b % 2 == 0 ) bb = b-1;
    if ( a % 2 == 0 ) a = 0;
    if ( b % 2 == 1 ) b = 0;
    cout << ((a^b)^(((bb - aa + 1 ) / 2 ) % 2 == 1 )) << endl;
}
int main()
{
    //freopen("LINCAN.inp","r",stdin);
    cin >> q;
    while ( q-- ) {
        cin >> a >> b;
        solve(a,b);
    }
}
