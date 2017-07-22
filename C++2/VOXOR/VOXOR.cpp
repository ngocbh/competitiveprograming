#include <bits/stdc++.h>

using namespace std;
const long N = 500000 + 10;

int n, m, q;
int a[N], b[N];

void solve(int k)
{
    for (int i = 1; i <= n; i++) b[i] = a[i];
    sort(b+1,b+n+1,greater<int>() );
    cout << b[k] << endl;
}

int main()
{
    //freopen("VOXOR.inp","r",stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= q; i++) {
        string s; int x;
        cin >> s >> x;

        if ( s[0] == 'X' ) { for (int i = 1; i <= n; i++) a[i] = a[i] ^ x; }
        else solve(x);
    }

}
