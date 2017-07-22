#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n, h[N], a[N];

int main()
{   //freopen("B.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    a[n+1] = 0;
    for (int i = n; i >= 1; i--) {
        a[i] = max(h[i],a[i+1]);
    }
    for (int i = 1; i <= n; i++)
        cout << max(h[i],(a[i+1] + 1)) - h[i] << " ";

}
