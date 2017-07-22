#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;
typedef long long LL;

int n;
LL a[N], x[N], f[N], w[N], e[N];

int main()
{
    //freopen("VOMARIO.inp","r",stdin);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> w[i] >> e[i];
	LL ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
        {
            if ( f[j] - w[j]*abs(x[i]-x[j]) < 0 ) continue;
            f[i] = max(f[i],f[j] - w[j]*abs(x[i]-x[j]) + e[i]);
            ans = max(ans,f[i]);
        }

    cout << ans;
}


