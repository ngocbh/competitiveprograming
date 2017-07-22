#include <bits/stdc++.h>

const long N = 1000;
using namespace std;
int n, ans;
int main()
{   //freopen("A.inp","r",stdin);
    cin >> n;
    ans = 10000000;
    for (int i = 1; i <= n; i++) {
            int a;
            //AAAAAAAAAAAAAAAAAAAAAAAAAA
            cin >> a;
            ans = min(ans , a);
            //AAAAAAAAAAAAAAAAAAAAAAAAA
    }
    if ( ans == 1 ) cout << -1;
    //AAAAAAAAAAAAAAAAAAAAAAAAAA
    else cout << 1;

}
