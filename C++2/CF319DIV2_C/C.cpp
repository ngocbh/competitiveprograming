#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
int n, k, ca[N], res[N];
int main()
{  // freopen("C.inp","r",stdin);
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    for (int i = 2; i <= n; i++) {
            if ( !ca[i] ) {
                for (int j = 1; i*j <= n; j++) ca[i*j] = true;
                int x = i;
                for (int j= 1; x <= n; ++j) {
                    res[++ans] = x;
                    x = x*i;
                }
            }
    }
    cout << ans << endl;
    for (int i =1 ; i <= ans; i++) cout << res[i] << " ";
}
