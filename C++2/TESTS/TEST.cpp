#include <bits/stdc++.h>

const long N = 100;
using namespace std;
int n , x, a[N];
int main()
{   freopen("TEST.inp","r",stdin);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int c = upper_bound(a+1,a+n+1,x) - a;
    cout << c;

}
