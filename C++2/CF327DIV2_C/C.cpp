#include <bits/stdc++.h>

const long N = 100000 * 5 + 10;
using namespace std;

int n, ans;
int a[N], f[N], b[N];

void solve(int l,int r)
{
    while ( true ) {
        if ( r < l ) return;
        b[l] = b[l-1];
        b[r] = b[r+1];
        ++l;
        --r;
    }
}

int main()
{   //freopen("C.inp","r",stdin);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];

    a[n+1] = a[n];
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i-1] && a[i] != a[i+1] ) {
            f[i] = f[i-1] + 1;
            ans = max(ans,(int)ceil((double) f[i]/2));
        }
        else {
            f[i] = 0;
            solve(i-f[i-1],i-1);
        }

    cout << ans << endl;
    for (int i = 1; i <= n; i++) cout << b[i] << " ";

}
