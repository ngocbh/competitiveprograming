/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

#define x first
#define y second

const long N = 300000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m;
LL f[N];
ii a[N], b[N];

int main()
{
    //freopen("GROUP.inp","r",stdin);
    //freopen("GROUP.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i].x >> b[i].y;

    sort(b+1,b+n+1);

    int ymax = 0;
    for (int i = n; i >= 0; i--) {
        if ( ymax >= b[i].y ) continue;
        a[++m] = b[i];
        ymax = max(ymax,b[i].y);
    }
    n = m;

    sort(a+1,a+n+1);

    for (int i = 1; i <= n; i++) {
        f[i] = oo*oo;
        for (int j = 0; j < i; j++)
            f[i] = min(f[i],f[j] + 1LL * a[i].x * a[j+1].y);
    }

    cout << f[n];
}
