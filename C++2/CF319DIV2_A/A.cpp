#include <bits/stdc++.h>


using namespace std;
int n, x;
int main()
{       //freopen("A.inp","r",stdin);
        cin >> n >> x;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if ( x % i == 0 && x / i <= n )
            ++ans;

        }
        cout << ans;

}
